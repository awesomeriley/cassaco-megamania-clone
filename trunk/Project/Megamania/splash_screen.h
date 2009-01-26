/**
 * Arquivo que define a interface publica para a classe 
 * SplashScreen responsavel por somente exibir o logo da
 * empresa por alguns segundos e depois direcionar para a
 * a pr�xima tela.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __SPLASH_SCREEN_H__
#define __SPLASH_SCREEN_H__

#include "SDL.h"
#include "SDL_image.h"
#include "game_config.h"

Uint32 TimerCallback(Uint32, void*);

class SplashScreen 
{
    
    private:
		SDL_Surface *screen;
		SDL_Surface *icon;
		SDL_Surface *logo;
		SDL_Surface *msg;
		SDL_Surface * LoadImage(const char *file);
	public:
		SplashScreen(SDL_Surface *screen)throw();
		~SplashScreen(void);
		void Show(void);
		SDL_Surface *getMsg(void)const;
};

#endif //__SPLASH_SCREEN_H__