/**
 * Implementa��o da classe MenuScreen responsavel por 
 * exibir o menu de op��es do jogo.
 * Atualmente este menu apresenta as op��es:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com)
 * 
 */
#include "menu_screen.h"
#include "megamania_utils.h"
#include "log.h"
#include <string>

namespace Megamania
{
	/**
	 * Construtor default que cria um novo objeto MenuScreen 
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 */
	MenuScreen::MenuScreen(SDL_Surface *screen)throw(SDLVideoException)
	{   
		if(screen == NULL) {
			throw SDLVideoException("SDL Video n�o inicializado");
		}
		
		//TODO colocar esses valores em um XML
		this->screen = screen;
		int buttonsX = 500;
		int buttonsY = 250;
		int verticalspace = 80;
		
		background = LoadImage(MENU_BACKGROUND);
		startBT   = new CSButton(MENU_BUTTON, buttonsX, buttonsY);
		scoreBT   = new CSButton(MENU_BUTTON, buttonsX, buttonsY + verticalspace);
		optionsBT = new CSButton(MENU_BUTTON, buttonsX, buttonsY + 2*verticalspace);
		creditsBT = new CSButton(MENU_BUTTON, buttonsX, buttonsY + 3*verticalspace);

		startBT->SetLabel(MENU_START_LABEL);
		scoreBT->SetLabel(MENU_SCORE_LABEL);
		optionsBT->SetLabel(MENU_OPTIONS_LABEL);
		creditsBT->SetLabel(MENU_CREDITS_LABEL);
		
		SDL_WM_SetCaption(MENU_SCREEN_TITLE, NULL);
		//TODO set icon
	}

	/**
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela MenuScreen
	 */
	MenuScreen::~MenuScreen() 
	{    
		SDL_FreeSurface(this->background);
		delete startBT;
		delete scoreBT;
		delete optionsBT;
		delete creditsBT;
	}

	void MenuScreen::Show(void) 
	{
		SDL_Event event;
		
		SDL_BlitSurface(startBT->surface, NULL, background, &startBT->surface->clip_rect);
		SDL_BlitSurface(scoreBT->surface, NULL, background, &scoreBT->surface->clip_rect);
		SDL_BlitSurface(optionsBT->surface, NULL, background, &optionsBT->surface->clip_rect);
		SDL_BlitSurface(creditsBT->surface, NULL, background, &creditsBT->surface->clip_rect);
		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);

		for(;;) {
			if((SDL_PollEvent(&event)) != 0) {
				if((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE)) {
					break;
				}else{
					//TODO Refactory!!!
					startBT->FireChangeImageEvent(&event);
					scoreBT->FireChangeImageEvent(&event);
					optionsBT->FireChangeImageEvent(&event);
					creditsBT->FireChangeImageEvent(&event);
					SDL_BlitSurface(startBT->surface, NULL, background, &startBT->surface->clip_rect);
					SDL_BlitSurface(scoreBT->surface, NULL, background, &scoreBT->surface->clip_rect);
					SDL_BlitSurface(optionsBT->surface, NULL, background, &optionsBT->surface->clip_rect);
					SDL_BlitSurface(creditsBT->surface, NULL, background, &creditsBT->surface->clip_rect);
					SDL_BlitSurface(background, NULL, screen, NULL);
					SDL_Flip(screen);
				}
			}		
		}    
	}
}