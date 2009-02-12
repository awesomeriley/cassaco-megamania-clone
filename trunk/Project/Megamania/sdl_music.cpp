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
#include "sdl_music.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor padrão responsavel por criar um novo objeto
	 * Music, o construtor também irá iniciar o sistema
	 * SDL_mixer
	 **************************************************************/
	Music::Music(void)
	{
	}

	/*******************************************************************
	 * Destruidor responsavel por desalocar todos os recursos alocados
	 * pela SDL_mixer
	 *
	 ******************************************************************/
	Music::~Music(void) 
	{
		Close();
	}

	/***************************************************************
	 * Função responsavel por carregar um arquivo que contém uma
	 * musica qualquer a ser tocada, esta função poderá carregar 
	 * os seguintes tipos de musica:
	 * 
	 * - MP3
	 * - MOD
	 * - WAV
	 * - MIDI
	 * - OBB
	 * Dentre outras
	 *
	 **************************************************************/
	void Music::Load(const char *file)throw(SDLAudioException)
	{
		if((music = Mix_LoadMUS(file)) == NULL) {
			throw SDLAudioException("Erro ao carregar arquivo de audio");
		}
	}
	
	/***************************************************************
	 * Função responsavel por resetar a musica, fazendo a mesma
	 * ir para o inicio
	 *
	 **************************************************************/
	void Music::Rewind(void) 
	{
		Mix_RewindMusic();
	}

	/***************************************************************
	 * Função que seta o cursor que indica a posição corrente da
	 * musica em uma posição aleatoria do arquivo
	 *
	 * bool -> caso seja retornado true indica que a função executou
	 * com sucesso e false caso contrario
	 *
	 **************************************************************/
	bool Music::Seek(double position) 
	{
		return static_cast<bool>(Mix_SetMusicPosition(position));
	}

	/***************************************************************
	 * Função responsavel por modificar o volume seja
	 * para aumentar ou diminuir,
	 * O volume minimo para o "chunk" é 0 e o máximo
	 * é 128 definido pela constante MIX_MAX_VOLUME
	 *
	 **************************************************************/
	void Music::SetVolume(int volume) 
	{   
		Mix_VolumeMusic((volume < 0) ? 0 : (volume > MIX_MAX_VOLUME) ? MIX_MAX_VOLUME : volume);
							   
	}

	/***************************************************************
	 * Função responsavel por tocar a musica, a musica somente será
	 * tocado uma unica vez
	 *
	 **************************************************************/
	void Music::Play(void) 
	{
		Mix_PlayMusic(music, 0); 
	}

	/***************************************************************
	 * Função responsavel por parar a execução da musica
	 *
	 **************************************************************/
	void Music::Stop(void) 
	{
		Mix_HaltMusic();
	}

	/***************************************************************
	 * Função que realiza um efeito de fade-in gradualmente 
	 * baseado no parametro informado que indica o tempo em 
	 * millisegundos
	 *
	 **************************************************************/
	void Music::FadeIn(int milli) 
	{
		Mix_FadeInMusic(music, 0, milli);
	}

	/***************************************************************
	 * Função que realiza um efeito de fade-out gradualmente 
	 * baseado no parametro informado que indica o tempo em 
	 * millisegundos
	 *
	 **************************************************************/
	void Music::FadeOut(int milli) 
	{
		Mix_FadeOutMusic(milli);
	}

	/***************************************************************
	 * Função que retorna o tipo de musica que está sendo tocada
	 * esta função poderá retornar um dos seguintes valores abaixo:
	 *
	 * - NONE -> desconhecido
	 * - WAV -> arquivo wave windows
	 * - MID -> arquivo midi (Musical Instrument Digital Interface)
	 * - OGG -> arquivo ogg (Vorbis)
	 * - MOD -> arquivo mod
	 * - MP3 -> arquivo mp3 (MPEG-1/2 Audio Layer 3)
	 *
	 **************************************************************/
	const char * Music::GetType(void)const
	{
		switch(Mix_GetMusicType(music)) {
			case Mix_MusicType::MUS_CMD:
			case Mix_MusicType::MUS_NONE:
				return "NONE";
			case Mix_MusicType::MUS_MOD:
				return "MOD";
			case Mix_MusicType::MUS_OGG:
				return "OGG";
			case Mix_MusicType::MUS_MID:
				return "MID";
			case Mix_MusicType::MUS_WAV:
				return "WAV";
			case Mix_MusicType::MUS_MP3:
			case Mix_MusicType::MUS_MP3_MAD:
				return "MP3";
			default:
				return "NONE";
		}	
	}

	/***************************************************************
	 * Função responsavel por fechar todos os recursos
	 * alocados pela SDL_mixer
	 *
	 **************************************************************/
	void Music::Close(void) 
	{
		if(music != NULL) {
			Mix_FreeMusic(music);
			music = NULL;
		}		
	}
}