package anim;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;
import javax.microedition.lcdui.game.Sprite;

public class AnimCanvas extends GameCanvas implements Runnable{
  
  private final int girlXVel = 4;
  private int[] WALK = {1, 2, 3, 4, 5, 6, 7, 8};
  private int[] STAND = {0};
  private int sleepTime = 60;
  private int girlY = 0;
  private int girlX = 0;
  private boolean isWalking = false;
  private Image girl;
  private Sprite girlSprite;


  public AnimCanvas() {
    super(false);
  }

  public void start() {
    try {
      girl = Image.createImage("/girl_sprites.png");
      girlSprite = new Sprite(girl, 64, 64);
      girlSprite.setRefPixelPosition(girlSprite.getWidth()/2, girlSprite.getHeight()/2);
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
    g.setColor(200, 200, 200);
    g.fillRect(0, 0, getWidth(), getHeight());
  }

  private void updateScreen(Graphics g) {
    createBackground(g);
    girlSprite.setPosition(girlX, girlY);
    
    if (getKeyStates() != 0) {
      moveGirl(g);
    } else {
      standGirl(g);
    }
    flushGraphics();
  }

  private void moveGirl(Graphics g) {
    int keyState = getKeyStates();
    
    if ((keyState & RIGHT_PRESSED) != 0 && girlX < (getWidth() - girlSprite.getWidth())) {
      girlSprite.setTransform(Sprite.TRANS_NONE);
      
      if (!isWalking) {
        isWalking = true;
        girlSprite.setFrameSequence(this.WALK);
      } else {
        girlSprite.nextFrame();
        girlSprite.paint(g);
      }
      girlX += girlXVel;
    } else if ((keyState & LEFT_PRESSED) != 0 && girlX > 0) {
      girlSprite.setTransform(Sprite.TRANS_MIRROR);
      
      if (!isWalking) {
        isWalking = true;
        girlSprite.setFrameSequence(this.WALK);
      } else {
        girlSprite.nextFrame();
        girlSprite.paint(g);
      }
      girlX -= girlXVel;
    }
  }
  
  private void standGirl(Graphics g) {
    isWalking = false;
    girlSprite.setFrameSequence(this.STAND);
    girlSprite.nextFrame();
    girlSprite.paint(g);
  }
}