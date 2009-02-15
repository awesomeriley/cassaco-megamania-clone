/**********************************************************************
 * Classe responsavel por manipular os dados relacionados com 
 * os sons do jogo 
 * Esta classe possui operações básicas com tocar um som
 * aumentar e diminuir o volume do som e pausar.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 *********************************************************************/
#ifndef __SDL_EFFECT_H__
#define __SDL_EFFECT_H__

#include "SDL_mixer.h"
#include "sdl_sound.h"
#include "audio_exception.h"

#define MIX_AVAILABLE_CHANNEL MIX_PLAY_FOREVER

namespace Megamania
{
	class Effect : public Sound
	{
		private:
			/** Objeto que representa a abstração para todo efeito sonoro*/
			Mix_Chunk *chunk;
			/** variavel que indica o canal alocado para tocar o efeito sonoro*/
			int idChannel;
		public:
			Effect(void);
			~Effect(void);		    
			void Load(const char *)throw(SDLAudioException);
			void SetVolume(int volume = MIX_MAX_VOLUME);
			int Play(void);
			void Close(void);
	};
}

#endif //__SDL_EFFECT_H__
