/******************************************************************
 * Arquivo que define a interface publica para a classe 
 * MenuScreen MenuScreen responsavel por 
 * exibir o menu de opções do jogo.
 * Atualmente este menu apresenta as opções:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com)
 * 
 *****************************************************************/
#ifndef __MENU_SCREEN_H__
#define __MENU_SCREEN_H__

#include "SDL.h"
#include "cs_button.h"
#include "game_config.h"
#include "video_exception.h"

namespace Megamania
{
	class MenuScreen 
	{
		private:
			SDL_Surface *screen;
			SDL_Surface *background;
			CSButton *startBT;
			CSButton *optionsBT;
			CSButton *scoreBT;
			CSButton *creditsBT;
			void RefreshAll(void);
			void EventTreatment(SDL_Event *);
			
		public:
			MenuScreen(SDL_Surface *screen)throw(SDLVideoException);
			~MenuScreen(void);
			void Show(void);
	};
}

#endif //__MENU_SCREEN_H__