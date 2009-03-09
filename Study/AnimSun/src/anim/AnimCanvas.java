package anim;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;
import javax.microedition.lcdui.game.Layer;
import javax.microedition.lcdui.game.LayerManager;
import javax.microedition.lcdui.game.Sprite;

public class AnimCanvas extends GameCanvas implements Runnable{

  private final int girlXVel = 4;
  private int[] WALK = {1, 2, 3, 4, 5, 6, 7, 8};
  private int[] STAND = {0};
  private int[] CROUCH = {9};
  private int sleepTime = 55;
  private int levelCount = 0;
  private int girlY = 90;
  private int girlX = 0;
  private int monsterX = 155;
  private int monsterY = 138;
  private boolean isWalking = false;
  private boolean monsterUp = true;
  private boolean monsterAlive = true;
  private Image girl;
  private Image monster;
  private Image background;
  private Sprite girlSprite;
  private Sprite monsterSprite;
  private Sprite BackgroundSprite;
  private LayerManager layerManager;


  public AnimCanvas() {
    super(false);
  }

  public void start() {
    try {
      girl = Image.createImage("/girl_sprites.png");
      monster = Image.createImage("/monstro.png");
      background = Image.createImage("/bg.png");
      girlSprite = new Sprite(girl, 64, 64);
      girlSprite.setPosition(girlX, girlY);
      monsterSprite = new Sprite(monster, 12, 14);
      monsterSprite.setPosition(monsterX, monsterY);
      BackgroundSprite = new Sprite(background);
      layerManager = new LayerManager();
      layerManager.append(girlSprite);
      layerManager.append(monsterSprite);
      layerManager.append(BackgroundSprite);
    } catch (Exception e) {
      e.printStackTrace();
    }

    Thread thread = new Thread(this);
    thread.start();
  }

  public void run() {
    while(true) {
      try {
        updateScreen(getGraphics());
        Thread.sleep(sleepTime);
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }

  private void createBackground(Graphics g) {
    g.setColor(0);
    g.fillRect(0, 0, getWidth(), getHeight());
    layerManager.insert(BackgroundSprite, 1);

    if (levelCount == 0) {
      createMonster(g);
    }
  }

  private void createMonster(Graphics g) {
    if (monsterAlive) {
      layerManager.insert(monsterSprite, 1);
    }
  }

  private void moveMonster(Graphics g) {
    if (monsterAlive) {
      if (monsterUp) {
        monsterY -= 2;
        monsterSprite.setPosition(monsterX, monsterY);
        layerManager.insert(monsterSprite, 1);

        if (monsterY == 120) {
          monsterUp = false;
        }
      } else {
        monsterY += 2;
        monsterSprite.setPosition(monsterX, monsterY);
        layerManager.insert(monsterSprite, 1);

        if (monsterY == 138) {
          monsterUp = true;
        }
      }
    }
  }

  private void updateScreen(Graphics g) {
    createBackground(g);
    moveMonster(g);
    layerManager.paint(g, 32, 48);

    if (getKeyStates() != 0) {
      moveGirl(g);
    } else {
      standGirl(g);
    }
    flushGraphics();
  }

  private void moveGirl(Graphics g) {
    int keyState = getKeyStates();

    if ((keyState & RIGHT_PRESSED) != 0 && girlX < (BackgroundSprite.getWidth() - girlSprite.getWidth())) {
      girlSprite.setTransform(Sprite.TRANS_NONE);
      if (!isWalking) {
        isWalking = true;
        girlSprite.setFrameSequence(this.WALK);
      } else {
        girlSprite.nextFrame();
      }
      girlX += girlXVel;
      girlSprite.setPosition(girlX, girlY);
      layerManager.insert(girlSprite, 0);
    } else if ((keyState & LEFT_PRESSED) != 0 && girlX > 0) {
      girlSprite.setTransform(Sprite.TRANS_MIRROR);
      if (!isWalking) {
        isWalking = true;
        girlSprite.setFrameSequence(this.WALK);
      } else {
        girlSprite.nextFrame();
      }
      girlX -= girlXVel;
      girlSprite.setPosition(girlX, girlY);
      layerManager.insert(girlSprite, 0);
    }

    if ((keyState & RIGHT_PRESSED) != 0 && girlX == (BackgroundSprite.getWidth() - girlSprite.getWidth())) {
      if (levelCount < 1) {
        girlX = 0;
        girlSprite.setPosition(girlX, girlY);
        layerManager.insert(girlSprite, 0);
        layerManager.insert(changeBackground(), 1);
        levelCount += 1;
      }
    } else if ((keyState & LEFT_PRESSED) != 0 && girlX == 4) {
      if (levelCount != 0) {
        girlX = BackgroundSprite.getWidth() - girlSprite.getWidth();
        BackgroundSprite.setTransform(Sprite.TRANS_NONE);
        BackgroundSprite.setPosition(0, 0);
        girlSprite.setPosition(girlX, girlY);
        layerManager.insert(girlSprite, 0);
        layerManager.insert(BackgroundSprite, 1);
        levelCount -= 1;
      }
    }

    if ((keyState & DOWN_PRESSED) != 0) {
      crouchGirl(g);
    } 

    if ((keyState & DOWN_PRESSED) != 0 && girlSprite.collidesWith(monsterSprite, false)) {
      crouchGirl(g);
      monsterAlive = false;
      layerManager.remove(monsterSprite);
    }
  }

  private void standGirl(Graphics g) {
    isWalking = false;
    girlSprite.setFrameSequence(this.STAND);
    layerManager.insert(girlSprite, 0);
  }

  private void crouchGirl(Graphics g) {
    isWalking = false;
    girlSprite.setFrameSequence(this.CROUCH);
    layerManager.insert(girlSprite, 0);
  }

  private Layer changeBackground() {
    BackgroundSprite.setTransform(Sprite.TRANS_MIRROR);
    BackgroundSprite.setPosition(0, 0);
    return BackgroundSprite;
  }
}