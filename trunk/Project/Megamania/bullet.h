/*************************************************************
 * Classe que representa a bala do jogo, uma bala pode esta
 * associada tanto a nave principal, como a uma nave inimiga
 *
 * Author : Marcelo Collyer
 * Email : marcelocollyer@gmail.com
 *
 *************************************************************/
#ifndef __BULLET_H__
#define __BULLET_H__

#include "sprite_exception.h"
#include "game_config.h"
#include "game_object.h"

namespace Megamania
{
	class Bullet : public GameObject	
	{   		
		public:
			Bullet(void)throw(SpriteException);			
			void Update(Direction);
	};
}

#endif  //__BULLET_H__