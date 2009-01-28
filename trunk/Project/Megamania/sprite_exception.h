/**
 * Exceção que representa um erro caso ocorra
 * algum erro na criação de um objeto Sprite
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 */
#ifndef __SPRITE_EXCEPTION_H__
#define __SPRITE_EXCEPTION_H__

#include "base_exception.h"

namespace Megamania
{
	class SpriteException : public Exception 
	{
		public:
			SpriteException(const char *);          
	};
}

#endif //__SPRITE_EXCEPTION_H__