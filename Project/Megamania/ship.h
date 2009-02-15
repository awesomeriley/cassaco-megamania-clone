/*************************************************************
 * Classe base para todas os objetos que representam uma nave
 * no jogo, todas as classes que são naves devem ter esta
 * classe como super-classe
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author: Marcelo Collyer
 * Email : marcelocollyer@gmail.com
 *************************************************************/
#ifndef __SHIP_H__
#define __SHIP_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "bullet.h"
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
			/** Objeto que representa a bala da nave*/
			Bullet *bullet;		
			void ResetBulletPosition(void);
		public:
			Ship(const char *, Uint16, Uint16)throw(SpriteException);
			~Ship(void);
			virtual void Die(SDL_Surface *);
			virtual void Shoot(void);
			void SetState(ShipState);
			void GetState(ShipState &);
			void Draw(SDL_Surface *);
			void Event(SDL_Event *);			
			Bullet & GetBullet(void);
	};
}

#endif  //__SHIP_H__