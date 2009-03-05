/**
 * @file PongCanvas.java
 * @author Ernesto Janebro (janebro@gmail.com) 
 */

package pong;

import javax.microedition.lcdui.Display;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;

public class Pong extends MIDlet {
  
  PongCanvas pongCanvas;
  
  public Pong() {
    pongCanvas = new PongCanvas();
  }

  protected void destroyApp(boolean arg0) throws MIDletStateChangeException {

  }

  protected void pauseApp() {

  }

  protected void startApp() throws MIDletStateChangeException {
    Display display = Display.getDisplay(this);
    pongCanvas.start();
    display.setCurrent(pongCanvas);
  }
}
