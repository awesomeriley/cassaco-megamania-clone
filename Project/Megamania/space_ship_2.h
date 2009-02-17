/*************************************************************
 * Classe que representa a nave inimiga da fase dois.
 *
 * Author: Marcelo Collyer
 * Email : marcelocollyer@gmail.com  
 *
 *************************************************************/
#ifndef __SPACE_SHIP_2_H__
#define __SPACE_SHIP_2_H__

#include "enemy.h"
#include "sprite_exception.h"

namespace Megamania 
{
	class SpaceShip2 : public Enemy
	{
		private:
			/** variavel que indica o deslocamento no eixo X*/
			int dx;
			/** variavel que indica o deslocamento no eixo Y*/
			int dy;
			/** flag responsavel por indicar que a nave movimenta para baixo*/
			bool isDown;
		public: 
			SpaceShip2(void)throw(SpriteException);
			void Update(void);
			int GetPointValue(void);
	};
}

#endif //__SPACE_SHIP_2_H__