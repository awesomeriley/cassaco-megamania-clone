/******************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que dever�o
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
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * SDLVideoException -> exce��o disparada caso n�o seja possivel
	 * iniciar o Video
	 * 
	 **************************************************************/
	AbstractScreen::AbstractScreen(SDL_Surface *screen)throw(SDLVideoException)
	{
		if(screen == NULL) {
			throw SDLVideoException("SDL Video n�o inicializado");
		}
		this->screen = screen;
	}

	AbstractScreen::~AbstractScreen(void)
	{
	}
}