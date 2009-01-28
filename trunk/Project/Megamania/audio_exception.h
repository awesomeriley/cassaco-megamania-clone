/**
 * Exceção que representa um erro que ocorre quando
 * se tenta utilizar o sistema de AUDIO sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 */
#ifndef __AUDIO_EXCEPTION__
#define __AUDIO_EXCEPTION__

#include "base_exception.h"

class SDLAudioException : public Exception 
{
	public:
        SDLAudioException(const char *);          
};

#endif //__VIDEO_EXCEPTION__