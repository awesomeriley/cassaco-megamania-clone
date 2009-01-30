/*******************************************************************
 * Classe responsavel por iniciar o sistema SDL, esta classe 
 * deve ser chamada antes de se utilizar qualquer objeto do 
 * SDL
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ******************************************************************/
#include "initializer.h"
#include "log.h"
#include "SDL.h"
#include <cstdlib>

namespace Megamania
{
	/*****************************************************************
	 * Função responsavel por iniciar todos os SubSistema da Api SDL
	 *
	 ****************************************************************/
	void Initializer::Init(void) 
	{
		atexit(Initializer::Shutdow);
		if(SDL_WasInit(SDL_INIT_VIDEO) != 0) {
			if((SDL_Init(SDL_INIT_VIDEO)) == -1) {
				LOG_DEBUG(SDL_GetError());  
				LOG_ERROR("Erro ao criar surface\n");
				exit(EXIT_FAILURE);        
			}
		}	
	}

	/*****************************************************************
	 * Função responsavel por liberar todos os SubSistemas alocados
	 * pela Api SDL
	 *
	 ****************************************************************/
	void Initializer::Shutdow(void) 
	{    
		SDL_Quit();
	}
}
