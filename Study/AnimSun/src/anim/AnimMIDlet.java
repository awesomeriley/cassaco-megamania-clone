package anim;

import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;

public class AnimMIDlet extends MIDlet implements CommandListener{
  
  private AnimCanvas animCanvas;
  private Command exitCmd;
  
  public AnimMIDlet() {
    animCanvas = new AnimCanvas();
    exitCmd = new Command("Sair", Command.EXIT, 1);
    animCanvas.setCommandListener(this);
    animCanvas.addCommand(exitCmd);
  }

  protected void destroyApp(boolean arg0) throws MIDletStateChangeException {
    notifyDestroyed();
  }

  protected void pauseApp() {
    notifyPaused();
  }

  protected void startApp() throws MIDletStateChangeException {
    Display display = Display.getDisplay(this);
    animCanvas.start();
    display.setCurrent(animCanvas);
  }

  public void commandAction(Command command, Displayable display) {
    if (command == this.exitCmd) {
      notifyDestroyed();
    }
  }
}
