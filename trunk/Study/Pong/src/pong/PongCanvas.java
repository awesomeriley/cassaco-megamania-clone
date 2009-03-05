/**
 * @file PongCanvas.java
 * @author Ernesto Janebro (janebro@gmail.com) 
 */

package pong;

import java.io.IOException;
import java.util.Random;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import javax.microedition.lcdui.game.GameCanvas;
import javax.microedition.lcdui.game.Sprite;

public class PongCanvas extends GameCanvas implements Runnable{
  
  private final int sleepTime = 20;
  
  private final int ballYVel = 2;
  
  private final int ballXVel = 3;
  
  private final int racketYVel = 3;
  
  private final int cpuRacketYVel = 3;
  
  private final int racketX = 10;
  
  private int ballY = getHeight()/2;
  
  private int ballX = getWidth()/2;
  
  private int racketY = getWidth()/2;
  
  private int cpuRacketY = getWidth()/2;
  
  private int ballDirection = 0;
  
  private int actX;
  
  private Image ballImage;
  
  private Image racketImage;
  
  private Sprite ballSprite;
  
  private Sprite racketSprite;
  
  private Sprite cpuRacketSprite;
  
  
  /**
   * Default constructor
   */
  protected PongCanvas() {
    super(false);
  }

  public void run() {
    while(true) {
      try {
        updateScreen(getGraphics());
        Thread.sleep(sleepTime);
      } catch (Exception e) {
        System.out.println(e);
      }
    }
  }
  
  public void start() {
    try {
      ballImage = Image.createImage("/ball.png");
      racketImage = Image.createImage("/racket.png");
    } catch (IOException ioex) {
      System.out.println(ioex);
    }
    
    ballSprite = new Sprite(ballImage, 3, 3);
    racketSprite = new Sprite(racketImage, 3, 20);
    cpuRacketSprite = new Sprite(racketImage, 3, 20);
    
    Thread running = new Thread(this);
    running.start();
  }
  
  private void createBackground(Graphics g) {
    g.setColor(0);
    g.fillRect(0, 0, getWidth(), getHeight());
  }
  
  /**
   * @param g
   */
  public void updateScreen(Graphics g) {
    createBackground(g);
    moveBall();
    moveRacket();
    moveCpuRacket();
    ballSprite.paint(g);
    racketSprite.paint(g);
    cpuRacketSprite.paint(g);
    ballSprite.setPosition(ballX, ballY);
    racketSprite.setPosition(racketX, racketY);
    cpuRacketSprite.setPosition(getWidth() - (racketX + 3), cpuRacketY);
    flushGraphics();
  }
  
  private void moveBall() {
    if (ballDirection == 0) {
      ballX -= ballXVel;
      ballY -= ballYVel;
    } else if (ballDirection == 1) {
      ballX += ballXVel;
      ballY -= ballYVel;
    } else if (ballDirection == 2) {
      ballX -= ballXVel;
      ballY += ballYVel;
    } else if (ballDirection == 3) {
      ballX += ballXVel;
      ballY += ballYVel;
    }
    
    if (ballDirection == 0 && ballX < 0) {
      ballDirection = 1;
    } else if (ballDirection == 0 && ballY < 0) {
      ballDirection = 2;
    } else if (ballDirection == 1 && ballX > getWidth()) {
      ballDirection = 0;
    } else if (ballDirection == 1 && ballY < 0) {
      ballDirection = 3;
    } else if (ballDirection == 2 && ballX < 0) {
      ballDirection = 3;
    } else if (ballDirection == 2 && ballY > getHeight()) {
      ballDirection = 0;
    } else if (ballDirection == 3 && ballX > getWidth()) {
      ballDirection = 2;
    } else if (ballDirection == 3 && ballY > getHeight()) {
      ballDirection = 1;
    }
    
    if (ballDirection == 0 && ballSprite.collidesWith(racketSprite, false)) {
      ballDirection = 1;
    } else if (ballDirection == 2 && ballSprite.collidesWith(racketSprite, false)) {
      ballDirection = 3;
    } else if (ballDirection == 1 && ballSprite.collidesWith(cpuRacketSprite, false)) {
      ballDirection = 0;
    } else if (ballDirection == 3 && ballSprite.collidesWith(cpuRacketSprite, false)) {
      ballDirection = 2;
    }
  }
  
  private void moveRacket() {
    int keyState = getKeyStates();
    
    if ((keyState & UP_PRESSED) != 0 && racketY > 0) {
      racketY -= racketYVel;
    } else if ((keyState & DOWN_PRESSED) != 0 && racketY < (getHeight() - racketSprite.getHeight())) {
      racketY += racketYVel;
    }
  }
  
  private void moveCpuRacket() {
    Random random = new Random();
    
    actX = getWidth() / 3 + Math.abs(random.nextInt() % (getWidth()/8)); 
    
    if (ballY < cpuRacketY && ballX > actX && cpuRacketY > cpuRacketSprite.getHeight()/2) {
      cpuRacketY -= cpuRacketYVel; 
    } else if (ballY > cpuRacketY && ballX > actX && cpuRacketY < getHeight() - cpuRacketSprite.getHeight()/2) { 
      cpuRacketY += cpuRacketYVel; 
    }
  }
}
