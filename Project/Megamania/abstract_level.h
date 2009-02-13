/***************************************************************
 * Classe que representa a classe base para todas as fases 
 * do jogo, toda fase deverá herdar diretamente desta classe
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __ABSTRACT_LEVEL_H__
#define __ABSTRACT_LEVEL_H__

#include "ship.h"
#include "enemy.h"
#include "video_exception.h"
#include "abstract_screen.h"
#include <vector>

namespace Megamania
{
	class AbstractLevel : public AbstractScreen
	{
		protected:
			/** vetor que contém os inimigos a serem exibidos*/
			std::vector<Enemy *> enemies;
			/** objeto que representa a nave principal do jogo*/
			Ship *megamania;
			/** flag que indica se o jogo já esta completo ou não*/
			bool levelComplete;
			/** variavel que indica a quantidade de naves por level*/
			Uint16 shipCount;
		public:
			AbstractLevel(SDL_Surface *)throw(SDLVideoException);
			~AbstractLevel(void);
			void SetMegamania(Ship *);
			void SetShipCount(Uint16);
			virtual void Init(void);
			virtual void Execute(void);
			virtual void Event(SDL_Event *);
            virtual void Draw(void);
			virtual void Clear(void);
	};
}

#endif //__ABSTRACT_LEVEL_H__