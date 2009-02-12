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
#include "sdl_effect.h"
#include "abstract_screen.h"
#include "video_exception.h"

namespace Megamania
{
	class SplashScreen : public AbstractScreen
	{
		private:
			/** surface que indica o logo da CASSACO*/
			SDL_Surface *logo;
			/** surface que representa a mensagem do splash_screen*/
			SDL_Surface *msg;
			/** Efeito sonoro que será tocado quando a tela for iniciada*/
			Effect   *stfSound; //abreviação para smell the fun Sound
		public:
			SplashScreen(SDL_Surface *)throw(SDLVideoException);
			~SplashScreen(void);
			SDL_Surface *GetMsg(void)const;
			Effect * GetSound(void)const;
			void Init(void);
			void Execute(void);
			void Event(SDL_Event *);
            void Draw(void);
			void Clear(void);
	};
}

#endif //__SPLASH_SCREEN_H__