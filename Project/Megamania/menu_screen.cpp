/***************************************************************
 * Implementação da classe MenuScreen responsavel por 
 * exibir o menu de opções do jogo.
 * Atualmente este menu apresenta as opções:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com) 
 *
 **************************************************************/
#include "menu_screen.h"
#include "megamania_utils.h"
#include "log.h"
#include <string>

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto MenuScreen 
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	MenuScreen::MenuScreen(SDL_Surface *screen)throw(SDLVideoException)
	{   
		if(screen == NULL) {
			throw SDLVideoException("SDL Video não inicializado");
		}

		if(TTF_Init() == -1){
			LOG_ERROR("Erro ao inicializar TTF [menu_screen]\n");
			exit(EXIT_FAILURE);        
		}

		//TODO colocar esses valores em um XML
		this->screen = screen;
		int buttonsX = MENU_BUTTON_X;
		int buttonsY = MENU_BUTTON_Y;
		int verticalspace = MENU_BUTTON_VERTICAL_SPACE;
		
		background = LoadImage(MENU_BACKGROUND);
		startBT   = new CSButton(MENU_BUTTON, buttonsX, buttonsY);
		scoreBT   = new CSButton(MENU_BUTTON, buttonsX, buttonsY + verticalspace);
		optionsBT = new CSButton(MENU_BUTTON, buttonsX, buttonsY + 2*verticalspace);
		creditsBT = new CSButton(MENU_BUTTON, buttonsX, buttonsY + 3*verticalspace);

		SDL_Color color = {MENU_BUTTON_COLOR_R, MENU_BUTTON_COLOR_G, MENU_BUTTON_COLOR_B};
		TTF_Font *font = TTF_OpenFont(MENU_FONT, MENU_BUTTON_FONT_SIZE);
		
		startBT->SetLabel(MENU_START_LABEL, font, color);
		scoreBT->SetLabel(MENU_SCORE_LABEL, font, color);
		optionsBT->SetLabel(MENU_OPTIONS_LABEL, font, color);
		creditsBT->SetLabel(MENU_CREDITS_LABEL, font, color);
		
		SDL_WM_SetCaption(MENU_SCREEN_TITLE, NULL);
		//TODO set icon
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela MenuScreen
	 *
	 **************************************************************/
	MenuScreen::~MenuScreen() 
	{    
		SDL_FreeSurface(this->background);
		delete startBT;
		delete scoreBT;
		delete optionsBT;
		delete creditsBT;
	}

	void MenuScreen::RefreshAll(void) 
	{
		SDL_BlitSurface(startBT->surface, NULL, background, &startBT->surface->clip_rect);
		SDL_BlitSurface(scoreBT->surface, NULL, background, &scoreBT->surface->clip_rect);
		SDL_BlitSurface(optionsBT->surface, NULL, background, &optionsBT->surface->clip_rect);
		SDL_BlitSurface(creditsBT->surface, NULL, background, &creditsBT->surface->clip_rect);
		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);
	}

	void MenuScreen::EventTreatment(SDL_Event *event) 
	{
		startBT->FireChangeImageEvent(event);
		scoreBT->FireChangeImageEvent(event);
		optionsBT->FireChangeImageEvent(event);
		creditsBT->FireChangeImageEvent(event);
	}

	void MenuScreen::Show(void) 
	{
		SDL_Event event;
		RefreshAll();
		
		for(;;) {
			if((SDL_PollEvent(&event)) != 0) {
				if((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE)) {
					break;
				}else{
					EventTreatment(&event);
					RefreshAll();
				}
			}		
		}    
	}
}
