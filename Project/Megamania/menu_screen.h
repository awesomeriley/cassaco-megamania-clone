/**
 * Arquivo que define a interface publica para a classe 
 * SplashScreen responsavel por somente exibir o logo da
 * empresa por alguns segundos e depois direcionar para a
 * a próxima tela.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
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
			
		public:
			MenuScreen(SDL_Surface *screen)throw(SDLVideoException);
			~MenuScreen(void);
			void Show(void);
	};
}

#endif //__MENU_SCREEN_H__