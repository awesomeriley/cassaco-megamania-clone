/*************************************************************
 * Classe que representa a classe base para todos os objetos
 * do JOGO, como por exemplo a nave inimiga, a nave principal
 * e a bala, todas as sub-classes devem ter esta classe como
 * a super-classe em sua hierarquia.
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
 *************************************************************/
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "sprite_exception.h"
#include "sdl_sprite.h"

namespace Megamania
{
	class GameObject : public Sprite
	{   
		protected:
			/** indica a quantidade de deslocamento em pixels a cada quadro*/
			int offset;
			/** indica a direção do ator*/
			int direction;
			/** Sprite responsavel por realizar a animação de morte*/
			Sprite *animation;
		public:
			GameObject(const char *, Uint16, Uint16)throw(SpriteException);
			virtual ~GameObject(void);
			void SetAnimation(const char *, Uint16, Uint16)throw(SpriteException);
	};
}

#endif  //__GAMEOBJECT_H__