/**
 * Classe responsavel por manipular os dados relacionados com 
 * os sons do jogo , bem como a musica.
 * Esta classe possui opera��es b�sicas com tocar um som, uma musica
 * realizar opera��es de FADE, aumentar e diminuir o volume do som
 * ou m�sica e pausar.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __SDL_SOUND_H__
#define __SDL_SOUND_H__

#include "SDL_mixer.h"
#include "audio_exception.h"

#define MIX_DEFAULT_CHUNK 4096
#define MIX_PLAY_FOREVER -1
#define MIX_AVAILABLE_CHANNEL MIX_PLAY_FOREVER

class SDL_Sound 
{
	private:
		Mix_Chunk *chunk;
    public:
		SDL_Sound(void)throw(SDLAudioException);
		~SDL_Sound(void);		    
		void Load(const char *file)throw(SDLAudioException);
		void SetVolume(int volume = MIX_MAX_VOLUME);
		void Play(void);
		void Close(void);

};

#endif //__SDL_SOUND_H__
