package anim;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;
import javax.microedition.lcdui.game.Sprite;

public class AnimCanvas extends GameCanvas implements Runnable{
  
  private int[] WALK = {1, 2, 3, 4, 5, 6, 7, 8};
  private int[] STAND = {0};
  private boolean isWalking = false;
  private Image girl;
  private Sprite girlSprite;
  

  protected AnimCanvas() {
    super(false);
  }
  
  public void start() {
    try {
      girl = Image.createImage("/girl_sprites.png");
      girlSprite = new Sprite(girl, 64, 64);
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
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }
  
  private void createBackground(Graphics g) {
    g.setColor(192, 192, 192);
    g.fillRect(0, 0, getWidth(), getHeight());
  }
  
  private void updateScreen(Graphics g) {
    createBackground(g);
    girlSprite.setPosition(getWidth()/2 - girlSprite.getWidth()/2, getHeight()/2 - girlSprite.getHeight()/2);
    if (!isWalking) {
      girlSprite.setFrameSequence(this.WALK);
      isWalking = true;
    } else {
      girlSprite.nextFrame();
      girlSprite.paint(g);
      flushGraphics();
    }
  }
}
