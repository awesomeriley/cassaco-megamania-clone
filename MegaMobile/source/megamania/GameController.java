package megamania;

/**
 * Classe respons�vel toda a l�gica de controle do jogo, bem como controle
 * de eventos, atualiza��o de tela, l�gica e fluxos do jogo.
 * @author camurca_ernesto
 *
 */
public class GameController {
	
	private static GameController gameController;
	
	/**
	 * Este m�todo retorna uma �nica instancia da classe GameController.
	 * @return gameController
	 */
	public GameController getInstance(){
		if (gameController == null) {
			gameController = new GameController();
		}
		return gameController;
	}
	
}
