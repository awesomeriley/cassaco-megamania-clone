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
		protected:
			/** indica a quantidade de deslocamento em pixels a cada quadro*/
			int offset;
			/** indica a direção do ator*/
			int direction;
			/** Sprite responsavel por realizar a animação de morte*/
			Sprite *animation;
		public:
			GameObject(const char *, Uint16, Uint16)throw(SpriteException);
			virtual ~GameObject(void);
			void SetAnimation(const char *, Uint16, Uint16)throw(SpriteException);
	};
}

#endif  //__GAMEOBJECT_H__