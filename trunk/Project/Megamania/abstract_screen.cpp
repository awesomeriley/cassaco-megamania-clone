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

#include <string.h>
#include "megamania_utils.h"
#include "game_config.h"

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
		SetTitle(GAME_TITLE);
		SetIcon(PATH_ICON_IMAGE);
	}
	
	/***************************************************************
	 * Destruidor padrão 
	 *
	 **************************************************************/
	AbstractScreen::~AbstractScreen(void)
	{
	}

	/***************************************************************
	 * Função responsavel por setar o titulo da tela, caso seja 
	 * passado como parametro um ponteiro NULL, nada ocorrerá
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
	 * Função responsavel por setar o novo ícone da tela, caso
	 * seja passado como parametro um ponteiro NULL, nada ocorrerá
	 * o ícone da tela deverá ser uma imagem 32x32
     *
	 * uri -> indica o path do ícone
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