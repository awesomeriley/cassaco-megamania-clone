/********************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que dever�o
 * ser implementadas por todas as sub-classes:
 *
 * -OnInit -> Fun��o responsavel por iniciar o estado da tela
 * -OnExecute -> Fun��o responsavel por exibir a tela 
 * -OnEvent -> Fun��o de callback que ser� chamada pelo gerenciador
 * de eventos quando ocorrer algum evento, repassando assim para a 
 * tela o evento que ocorreu
 * -OnDraw -> Fun��o responsavel por pintar ou repintar a tela
 * -OnClear -> Fun��o que deve ser chamada quando a tela n�o for
 * mais necessaria, realizando assim uma limpeza antes de sair
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 * 
 *******************************************************************/
#include "abstract_screen.h"

#include <string.h>
#include "megamania_utils.h"
#include "game_config.h"

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
		SetTitle(GAME_TITLE);
		SetIcon(PATH_ICON_IMAGE);
	}
	
	/***************************************************************
	 * Destruidor padr�o 
	 *
	 **************************************************************/
	AbstractScreen::~AbstractScreen(void)
	{
	}

	/***************************************************************
	 * Fun��o responsavel por setar o titulo da tela, caso seja 
	 * passado como parametro um ponteiro NULL, nada ocorrer�
	 *
	 * title -> indica o novo titulo da tela
	 *
	 **************************************************************/
	void AbstractScreen::SetTitle(const char *title)
	{
		if((title != NULL)&&(strlen(title))) {
			SDL_WM_SetCaption(title, NULL);
		}	
	}

	/***************************************************************
	 * Fun��o responsavel por setar o novo �cone da tela, caso
	 * seja passado como parametro um ponteiro NULL, nada ocorrer�
	 * o �cone da tela dever� ser uma imagem 32x32
     *
	 * uri -> indica o path do �cone
	 *
	 **************************************************************/
	void AbstractScreen::SetIcon(const char *uri)
	{
		if(uri != NULL) {
			SDL_Surface *icon = LoadImage(uri);
			SDL_WM_SetIcon(icon, NULL);
			SDL_FreeSurface(icon);
		}
	}
}