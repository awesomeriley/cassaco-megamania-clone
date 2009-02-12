/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas que
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __LEVEL_SCREEN_1_H__
#define __LEVEL_SCREEN_1_H__

#include <vector>
#include "enemy.h"
#include "ship.h"
#include "space_ship_1.h"
#include "abstract_screen.h"

namespace Megamania
{
	class LevelScreen : public AbstractScreen
	{
		private:
			/** vetor que contém os inimigos a serem exibidos*/
			std::vector<Enemy *> enemies;
			/** objeto que representa a nave principal do jogo*/
			Ship *megamania;
			bool levelComplete;
		public:
			LevelScreen(SDL_Surface *)throw(SDLVideoException);
			~LevelScreen(void);
			void Init(void);
			void Execute(void);
			void Event(SDL_Event *);
            void Draw(void);
			void Clear(void);
	};
}

#endif //__LEVEL_SCREEN_1_H__