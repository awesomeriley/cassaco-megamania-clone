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
#ifndef __BULLET_H__
#define __BULLET_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "sdl_sprite.h"

namespace Megamania
{
	class Bullet : public GameObject
	{   
		public:
			GameObject(const char *, Uint16, Uint16)throw(SpriteException);
			~GameObject(void);
	};
}

#endif  //__BULLET_H__