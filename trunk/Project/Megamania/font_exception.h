/*****************************************************************
 * Exceção que representa um erro que ocorre quando
 * se tenta utilizar o sistema de TTF sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ****************************************************************/
#ifndef __FONT_EXCEPTION_H__
#define __FONT_EXCEPTION_H__

#include "base_exception.h"

namespace Megamania
{
	class SDLFontException : public Exception 
	{
		public:
			SDLFontException(const char *);          
	};
}

#endif //__FONT_EXCEPTION_H__