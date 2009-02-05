/*************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *************************************************************/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "sdl_sprite.h"

namespace Megamania
{
	class Enemy : public Sprite
	{   
		/**
		 * Enumeration utilizado para indicar o estado atual do inimigo
		 */
		enum EnemyState { STOPPED, RUNNING, DIEING, DIE };

		protected:
			/** 
			 * flag responsavel por indicar um dos estados que
			 * um inimigo pode assumir
			 */
			EnemyState state;
			/** indica a direção do inimigo*/
			int direction;
			/** indica a posição anterior do inimigo no eixo x*/
			int lastX;
			/** indica a posição anterior do inimigo no eixo y*/
			int lastY;
			/** Sprite responsavel por realizar a animação de morte*/
			Sprite *dieing;
		public:
			Enemy(const char *, Uint16, Uint16)throw(SpriteException);
			~Enemy(void);
			void Die(SDL_Surface *);
			void Shoot(void);
			void SetDieAnimation(const char *, Uint16, Uint16);
			void SetState(EnemyState);
			void GetState(EnemyState &);
	};
}

#endif  //__ENEMY_H__