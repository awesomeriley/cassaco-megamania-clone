/*************************************************************
 * Classe que representa a nave inimiga da fase um, esta nave
 * somente se movimenta de um lado para outro.
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#ifndef __SPACE_SHIP_1_H__
#define __SPACE_SHIP_1_H__

#include "enemy.h"
#include "sprite_exception.h"

namespace Megamania 
{
	class SpaceShip1 : public Enemy
	{
		public: 
			SpaceShip1(void)throw(SpriteException);
			void Update(void);
	};
}

#endif //__SPACE_SHIP_1_H__