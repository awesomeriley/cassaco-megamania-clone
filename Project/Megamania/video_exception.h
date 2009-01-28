/**
 * Exceção que representa um erro que ocorre quando
 * se tenta utilizar o Video sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 */
#ifndef __VIDEO_EXCEPTION_H__
#define __VIDEO_EXCEPTION_H__

#include "base_exception.h"

namespace Megamania
{
	class SDLVideoException : public Exception 
	{
		public:
			SDLVideoException(const char *);          
	};
}

#endif //__VIDEO_EXCEPTION_H__