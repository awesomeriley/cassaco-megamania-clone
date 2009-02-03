/********************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que deverão
 * ser implementadas por todas as sub-classes:
 *
 * -OnInit -> Função responsavel por iniciar o estado da tela
 * -OnExecute -> Função responsavel por exibir a tela 
 * -OnEvent -> Função de callback que será chamada pelo gerenciador
 * de eventos quando ocorrer algum evento, repassando assim para a 
 * tela o evento que ocorreu
 * -OnDraw -> Função responsavel por pintar ou repintar a tela
 * -OnClear -> Função que deve ser chamada quando a tela não for
 * mais necessaria, realizando assim uma limpeza antes de sair
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 * 
 *******************************************************************/
#include "abstract_screen.h"

namespace Megamania
{

	/***************************************************************
	 * Construtor default que cria um novo objeto AbstractScreen 
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * SDLVideoException -> exceção disparada caso não seja possivel
	 * iniciar o Video
	 * 
	 **************************************************************/
	AbstractScreen::AbstractScreen(SDL_Surface *screen)throw(SDLVideoException)
	{
		if(screen == NULL) {
			throw SDLVideoException("SDL Video não inicializado");
		}
		this->screen = screen;
	}
	
	/***************************************************************
	 * Destruidor padrão 
	 *
	 **************************************************************/
	AbstractScreen::~AbstractScreen(void)
	{
	}
}