/*******************************************************************************
 * Classe responsavel por controlar toda a lógica do JOGO, está classe
 * é responsavel por inicializar todos os sistemas do SDL, capturar todos
 * os eventos e controlar a logica do jogo, como atualização de tela,
 * atualização de NPC etc.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 *******************************************************************************/
#ifndef __GAME_CONTROLLER_H__
#define __GAME_CONTROLLER_H__

#include "SDL.h"
#include "ship.h"
#include "game_config.h"
#include "splash_screen.h"
#include "level_screen_1.h"
#include "level_screen_2.h"
#include "level_screen_3.h"
#include "menu_screen.h"
#include "abstract_screen.h"

/** Estrutura global responsavel por controlar todos os eventos do GAME*/
static SDL_Event event;

namespace Megamania
{
	class GameController
	{
		private:
			/** unica instancia da classe*/
			static GameController *singleton;			
			/** ponteiro responsavel por apontar para a tela corrente*/
			AbstractScreen *currentScreen;
			/** flag responsavel por indicar se o jogo iniciou ou não*/
			bool running;
			/** variavel responsavel por armazenar o valor do tempo da ultima execução*/
			int lastTimer;
			/** variavel responsavel por armazenar o valor do tempo corrente*/
			int currentTimer;
			/** constante que indica a quantidade de frames por segundo*/
			static const int CLOCKS_PER_TICK = TIME_PER_TICKS;
			/** indica a largura da tela do jogo*/
			int width;
			/** indica a altura da tela do jogo*/
			int height;
			/** objeto que representa a nave principal do jogo*/
			Ship *megamania;
			GameController(void);
		public:
			static GameController & GetInstance(void) 
			{
				if(singleton == NULL) {
					singleton = new GameController();
				}
				return *singleton;
			}
			void InitSpashScreen(void);
			void InitMenuScreen(void);
			void LoadGame(void);
			void InitLevel(int);
			void OnGameInit(void);
			void OnGameLoop(void);
			void OnGameStop(void);
			void OnGameExit(void);
	};
}

#endif //__GAME_CONTROLLER_H__