/*************************************************************
 * Classe que representa a classe base para todas as naves 
 * inimigas, toda nave inimiga deve herdar desta classe e 
 * implementar a função Update(void) que indica como cada 
 * nave deve se mover
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "sprite_exception.h"
#include "ship.h"

namespace Megamania
{
	class Enemy : public Ship
	{   
		public:
			Enemy(const char *, Uint16, Uint16)throw(SpriteException);
			~Enemy(void);
			virtual void Update(void) = 0;
	};
}

#endif  //__ENEMY_H__