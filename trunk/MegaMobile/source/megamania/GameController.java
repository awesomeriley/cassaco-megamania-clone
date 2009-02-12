package megamania;

/**
 * Classe responsável toda a lógica de controle do jogo, bem como controle
 * de eventos, atualização de tela, lógica e fluxos do jogo.
 * @author camurca_ernesto
 *
 */
public class GameController {
	
	private static GameController gameController;
	
	/**
	 * Este método retorna uma única instancia da classe GameController.
	 * @return gameController
	 */
	public GameController getInstance(){
		if (gameController == null) {
			gameController = new GameController();
		}
		return gameController;
	}
	
}
