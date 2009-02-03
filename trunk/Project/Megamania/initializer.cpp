/*******************************************************************
 * Classe responsavel por iniciar o sistema SDL, esta classe 
 * deve ser chamada antes de se utilizar qualquer objeto do 
 * SDL
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ******************************************************************/
#include "initializer.h"
#include "game_config.h"
#include "log.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <cstdlib>

namespace Megamania
{
	/*****************************************************************
	 * Função responsavel por iniciar todos os SubSistema da Api SDL
	 *
	 ****************************************************************/
	void Initializer::Init(void) 
	{
		atexit(Initializer::Shutdown);
		if(SDL_WasInit(SDL_INIT_EVERYTHING) != 0) {
			if((SDL_Init(SDL_INIT_EVERYTHING)) == -1) {
				LOG_DEBUG(SDL_GetError());  
				LOG_ERROR("Erro ao iniciar sistema de Video");
				exit(EXIT_FAILURE);        
			}
		}	
		if(TTF_Init() == -1) {
			LOG_DEBUG(TTF_GetError());
			LOG_ERROR("Erro ao iniciar sistema TTF");
			exit(EXIT_FAILURE);
		}
		if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 
						 MIX_DEFAULT_CHANNELS, MIX_DEFAULT_CHUNK_BUFFER_SIZE) == -1) {
			LOG_DEBUG(Mix_GetError());
			LOG_ERROR("SDL Audio não inicializado");
			exit(EXIT_FAILURE);
		}
	}

	/*****************************************************************
	 * Função responsavel por liberar todos os SubSistemas alocados
	 * pela Api SDL
	 *
	 ****************************************************************/
	void Initializer::Shutdown(void) 
	{   
		TTF_Quit();
		Mix_CloseAudio();
		SDL_Quit();
	}
}
