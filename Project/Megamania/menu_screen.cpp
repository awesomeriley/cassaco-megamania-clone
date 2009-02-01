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
		//TODO colocar esses valores em um XML
		this->screen = screen;
		int x = MENU_BUTTON_X;
		int y = MENU_BUTTON_Y;
		int vSpace = MENU_BUTTON_VERTICAL_SPACE;
		
		background = LoadImage(MENU_BACKGROUND);
		startBT   = new CSButton(MENU_BUTTON, x, y);
		scoreBT   = new CSButton(MENU_BUTTON, x, y + vSpace);
		optionsBT = new CSButton(MENU_BUTTON, x, y + (vSpace << 1));               // vSpace * 2
		creditsBT = new CSButton(MENU_BUTTON, x, y + ((vSpace << 1) + vSpace));    // vSpace * 3
		SDL_Color color;
		color.r = MENU_BUTTON_COLOR_R;
		color.g = MENU_BUTTON_COLOR_G;
		color.b = MENU_BUTTON_COLOR_B;
		SDL_Font *font = new SDL_Font(MENU_FONT, MENU_BUTTON_FONT_SIZE);
		startBT->SetFont(font);
		scoreBT->SetFont(font);
		optionsBT->SetFont(font);
		creditsBT->SetFont(font);
		startBT->SetText(MENU_START_LABEL);
		scoreBT->SetText(MENU_SCORE_LABEL);
		optionsBT->SetText(MENU_OPTIONS_LABEL);
		creditsBT->SetText(MENU_CREDITS_LABEL);		
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
		startBT->Draw(background);
		scoreBT->Draw(background);		
		optionsBT->Draw(background);		
		creditsBT->Draw(background);		
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
				} else {
					EventTreatment(&event);
					RefreshAll();
				}
			}		
		}    
	}
}
