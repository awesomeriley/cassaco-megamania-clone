/******************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que deverão
 * ser implementadas por todas as sub-classes:
 *
 *
 *
 *
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 * 
 *****************************************************************/
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

	AbstractScreen::~AbstractScreen(void)
	{
	}
}