/*******************************************************************************
 * Classe responsavel por controlar toda a lógica do JOGO, está classe
 * é responsavel por inicializar todos os sistemas do SDL, capturar todos
 * os eventos e controlar a logica do jogo, como atualização de tela,
 * atualização de NPC etc.
 *
 *  Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 *******************************************************************************/
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "game_config.h"
#include "SDL.h"
#include "splash_screen.h"
#include "menu_screen.h"

namespace Megamania
{
	class GameController
	{
		private:
			/** unica instancia da classe*/
			static GameController *singleton;
			/** container utilizado para renderizar todos os graficos do jogo*/
			SDL_Surface *mainScreen;
			/** flag responsavel por indicar se o jogo iniciou ou não*/
			bool running;
			/** constante que indica a quantidade de frames por segundo*/
			static const int CLOCKS_PER_TICK = 50;
			/** indica a largura da tela do jogo*/
			int width;
			/** indica a altura da tela do jogo*/
			int height;
			/** Objeto que representa a SplashScreen do jogo*/
			SplashScreen *splashScreen;
			/** Objeto que repreenta o Menu do jogo*/
			MenuScreen *menuScreen;
		public:
			GameController(void) 
			{
				width = WIDTH_SCREEN;
				height = HEIGHT_SCREEN;
				running = false;
				mainScreen = screen;
				splashScreen = new SplashScreen(mainScreen);
				menuScreen = new MenuScreen(mainScreen);
			}			
			static GameController * GetInstance(void) 
			{
				if(singleton == NULL) {
					singleton = new GameController();
				}
				return singleton;
			}
			void InitSpashScreen(void);
			void InitMenuScreen(void);
			void OnGameInit(void);
			void OnGameEvent(SDL_Event *event);
			void OnGameStop(void);
			void OnGameExit(void);
			void OnGameDraw(void);
	};
}

#endif //__GAME_CONTROLLER_H__