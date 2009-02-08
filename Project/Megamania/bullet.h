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

#include "sprite_exception.h"
#include "game_object.h"

namespace Megamania
{
	class Bullet : public GameObject	
	{   
		public:
			Bullet(const char *, Uint16, Uint16)throw(SpriteException);
			~Bullet(void);
	};
}

#endif  //__BULLET_H__