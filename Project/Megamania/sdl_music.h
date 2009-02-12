/*********************************************************************
 * Classe que representa uma musica, esta classe possui as seguintes
 * operações basicas: 
 * 
 * - Fade-in 
 * - Fade-out
 * - Rewind
 * - Stop
 * - Play
 * - Seek
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ********************************************************************/
#ifndef __SDL_MUSIC_H__
#define __SDL_MUSIC_H__

#include "SDL_mixer.h"
#include "sdl_sound.h"
#include "audio_exception.h"

namespace Megamania
{
	class Music : public Sound
	{
		private:
			/** Objeto que representa uma musica a ser tocada*/
			Mix_Music *music;
		public:
			Music(void);
			~Music(void);
			void Load(const char *)throw(SDLAudioException);
			void SetVolume(int volume = MIX_MAX_VOLUME);
			void FadeIn(int);
			void FadeOut(int);
			bool Seek(double);
			void Rewind(void);
			int Play(void);
			void Stop(void);
			void Close(void);
			const char * GetType(void)const;
	};
}

#endif //__SDL_MUSIC_H__