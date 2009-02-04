/*********************************************************************
 * Classe responsavel por manipular os dados relacionados com 
 * os sons do jogo , bem como a musica.
 * Esta classe possui opera��es b�sicas com tocar um som, uma musica
 * realizar opera��es de FADE, aumentar e diminuir o volume do som
 * ou m�sica e pausar.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ********************************************************************/
#include "sdl_sound.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor padr�o responsavel por criar um novo objeto
	 * SDL_Sound, o construtor tamb�m ir� iniciar o sistema
	 * SDL_mixer
	 **************************************************************/
	SDL_Sound::SDL_Sound(void)
	{
	}

	/*******************************************************************
	 * Destruidor responsavel por desalocar todos os recursos alocados
	 * pela SDL_mixer
	 *
	 ******************************************************************/
	SDL_Sound::~SDL_Sound(void) 
	{
		Close();
	}

	/***************************************************************
	 * Fun��o responsavel por carregar um arquivo .wav que
	 * cont�m o "chunk" a ser tocado, um "chunk" se caracteriza
	 * por ser um som qualquer
	 *
	 **************************************************************/
	void SDL_Sound::Load(const char *file)throw(SDLAudioException)
	{
		if((chunk = Mix_LoadWAV(file)) == NULL) {
			throw SDLAudioException("Erro ao carregar arquivo de audio");
		}
	}

	/***************************************************************
	 * Fun��o responsavel por modificar o volume seja
	 * para aumentar ou diminuir,
	 * O volume minimo para o "chunk" � 0 e o m�ximo
	 * � 128 definido pela constante MIX_MAX_VOLUME
	 *
	 **************************************************************/
	void SDL_Sound::SetVolume(int volume) 
	{   
		Mix_VolumeChunk(chunk, (volume < 0) ? 0 : (volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume);
							   
	}

	/***************************************************************
	 * Fun��o responsavel por tocar o "chunk" o som ser�
	 * tocado somente uma unica vez
	 *
	 **************************************************************/
	void SDL_Sound::Play(void) 
	{
		Mix_PlayChannel(MIX_AVAILABLE_CHANNEL, chunk, 0);
	}

	/***************************************************************
	 * Fun��o responsavel por fechar todos os recursos
	 * alocados pela SDL_mixer
	 *
	 **************************************************************/
	void SDL_Sound::Close(void) 
	{
		if(chunk != NULL) {
			Mix_FreeChunk(chunk);
			chunk = NULL;
		}		
	}
}