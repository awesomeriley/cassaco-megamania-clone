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
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "sdl_sprite.h"

namespace Megamania
{
	class GameObject : public Sprite
	{   
		/**
		 * Enumeration utilizado para indicar o estado atual do ator
		 */
		enum GameObjectState { STOPPED, RUNNING, DYING, DIE };

		protected:
			/** 
			 * flag responsavel por indicar um dos estados que
			 * um ator pode assumir
			 */
			GameObjectState state;
			/** indica a direção do ator*/
			int direction;
			/** Sprite responsavel por realizar a animação de morte*/
			Sprite *dying;
		public:
			GameObject(const char *, Uint16, Uint16)throw(SpriteException);
			~GameObject(void);
			void Die(SDL_Surface *);
			void Shoot(void);
			void SetDieAnimation(const char *, Uint16, Uint16);
			void SetState(GameObjectState);
			void GetState(GameObjectState &);
	};
}

#endif  //__GAMEOBJECT_H__