package anim;

import javax.microedition.lcdui.Display;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;

public class AnimMIDlet extends MIDlet {
  
  AnimCanvas animCanvas;
  
  public AnimMIDlet() {
    animCanvas = new AnimCanvas();
  }

  protected void destroyApp(boolean arg0) throws MIDletStateChangeException {

  }

  protected void pauseApp() {

  }

  protected void startApp() throws MIDletStateChangeException {
    Display display = Display.getDisplay(this);
    animCanvas.start();
    display.setCurrent(animCanvas);
  }
}
