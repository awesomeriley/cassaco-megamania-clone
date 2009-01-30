/***************************************************************
 * Arquivo que define a interface publica para a classe 
 * SplashScreen responsavel por somente exibir o logo da
 * empresa por alguns segundos e depois direcionar para a
 * a próxima tela.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __SPLASH_SCREEN_H__
#define __SPLASH_SCREEN_H__

#include "SDL.h"
#include "game_config.h"
#include "sdl_sound.h"
#include "video_exception.h"

Uint32 TimerCallback(Uint32, void*);

namespace Megamania
{
	class SplashScreen 
	{
		private:
			SDL_Surface *screen;
			SDL_Surface *icon;
			SDL_Surface *logo;
			SDL_Surface *msg;
			SDL_Sound   *stfSound; //abreviação para smell the fun Sound
		public:
			SplashScreen(SDL_Surface *screen)throw(SDLVideoException);
			~SplashScreen(void);
			void Show(void);
			SDL_Surface *GetMsg(void)const;
			SDL_Sound * GetSound(void)const;
	};
}

#endif //__SPLASH_SCREEN_H__