package anim;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;
import javax.microedition.lcdui.game.LayerManager;
import javax.microedition.lcdui.game.Sprite;

public class AnimCanvas extends GameCanvas implements Runnable{
  
  private final int girlXVel = 4;
  private int[] WALK = {1, 2, 3, 4, 5, 6, 7, 8};
  private int[] STAND = {0};
  private int sleepTime = 50;
  private int girlY = 90;
  private int girlX = 0;
  private boolean isWalking = false;
  private Image girl;
  private Image background;
  private Sprite girlSprite;
  private Sprite BackgroundSprite;
  private LayerManager layerManager;


  public AnimCanvas() {
    super(false);
  }

  public void start() {
    try {
      girl = Image.createImage("/girl_sprites.png");
      background = Image.createImage("/bg.png");
      girlSprite = new Sprite(girl, 64, 64);
      girlSprite.setPosition(girlX, girlY);
      BackgroundSprite = new Sprite(background);
      layerManager = new LayerManager();
      layerManager.append(girlSprite);
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
    
    if (girlX == (BackgroundSprite.getWidth() - girlX)) {
      BackgroundSprite.setTransform(Sprite.TRANS_MIRROR);
      layerManager.insert(BackgroundSprite, 1);
    }
    layerManager.insert(BackgroundSprite, 1);
  }

  private void updateScreen(Graphics g) {
    createBackground(g);
    
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
      System.out.println("Girl: " + girlX + "\nWIDTH: " + BackgroundSprite.getWidth());
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
  }
  
  private void standGirl(Graphics g) {
    isWalking = false;
    girlSprite.setFrameSequence(this.STAND);
    layerManager.insert(girlSprite, 0);
  }
}