/********************************************************************
 * Classe que representa a abstração para um som qualquer, podendo 
 * representar um efeito sonoro, bem como uma musica a ser tocada em
 * um canal exclusivo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ********************************************************************/
#ifndef __SDL_SOUND_H__
#define __SDL_SOUND_H__

#include "audio_exception.h"

#define MIX_PLAY_FOREVER -1

namespace Megamania
{
	class Sound
	{
		public:
			virtual ~Sound(void) {};
			virtual void Load(const char *)throw(SDLAudioException) = 0;
			virtual void SetVolume(int volume = MIX_MAX_VOLUME) = 0;
			virtual int Play(void) = 0;
			virtual void Close(void) = 0;
	};
}

#endif //__SDL_SOUND_H__
