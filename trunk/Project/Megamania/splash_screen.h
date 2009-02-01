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

namespace Megamania
{
	class SplashScreen 
	{
		private:
			/** referencia para a Surface principal do JOGO*/
			SDL_Surface *screen;
			/** surface que indica o icone da splash_screen*/
			SDL_Surface *icon;
			/** surface que indica o logo da CASSACO*/
			SDL_Surface *logo;
			/** surface que representa a mensagem do splash_screen*/
			SDL_Surface *msg;
			/** Efeito sonoro que será tocado quando a tela for iniciada*/
			SDL_Sound   *stfSound; //abreviação para smell the fun Sound
		public:
			SplashScreen(SDL_Surface *)throw(SDLVideoException);
			~SplashScreen(void);
			void Show(void);
			SDL_Surface *GetMsg(void)const;
			SDL_Sound * GetSound(void)const;
	};
}

#endif //__SPLASH_SCREEN_H__