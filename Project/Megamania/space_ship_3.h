/*************************************************************
 * Classe que representa a nave inimiga da fase tres.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)  
 *
 *************************************************************/
#ifndef __SPACE_SHIP_3_H__
#define __SPACE_SHIP_3_H__

#include "enemy.h"
#include "sprite_exception.h"

namespace Megamania 
{
	class SpaceShip3 : public Enemy
	{
		private:
		public: 
			SpaceShip3(void)throw(SpriteException);
			void Update(void);
			int GetPointValue(void);
	};
}

#endif //__SPACE_SHIP_3_H__