/**
 * Exceção que representa um erro que ocorre quando
 * se tenta utilizar o Video sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 */
#ifndef __VIDEO_EXCEPTION__
#define __VIDEO_EXCEPTION__

#include "base_exception.h"

class SDLVideoException : public Exception 
{
	public:
        SDLVideoException(const char *);          
};

#endif //__VIDEO_EXCEPTION__