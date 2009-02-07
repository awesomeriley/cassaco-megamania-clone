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
#include "game_object.h"

namespace Megamania
{
	class Ship : public GameObject
	{   
		/**
		 * Enumeration utilizado para indicar o estado atual da nave
		 */
		enum ShipState { STOPPED, RUNNING, DYING, DIE };
		protected:
			/** 
			 * flag responsavel por indicar um dos estados que
			 * um ator pode assumir
			 */
			ShipState state;
		public:
			Ship(const char *, Uint16, Uint16)throw(SpriteException);
			~Ship(void);
			void Die(SDL_Surface *);
			void Shoot(void);
			void SetState(ShipState);
			void GetState(ShipState &);
	};
}

#endif  //__SHIP_H__