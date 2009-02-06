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
#ifndef __SHIP_H__
#define __SHIP_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "sdl_sprite.h"
#include "game_object.h"

namespace Megamania
{
	class Ship : public GameObject
	{   
		public:
			Ship(const char *, Uint16, Uint16)throw(SpriteException);
			~Ship(void);
	};
}

#endif  //__SHIP_H__