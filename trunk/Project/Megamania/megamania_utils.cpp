/**
 * Arquivo que contém varias operações comuns utilizadas pelo
 * projeto MEGAMANIA, aqui são definidos todas as funções relacionadas
 * com carregamento de imagens, manipulação de Strings dentre outras
 * 
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#include "megamania_utils.h"

/**
 * Função responsavel por carregar o icone do Jogo, a imagem
 * de logo e a mensagem a ser exibida
 * 
 */
SDL_Surface * LoadImage(const char *file) 
{    
    SDL_Surface *image = NULL;
	if((image = IMG_Load(file)) == NULL) {
	    LOG_ERROR("Erro ao carregar imagen [LoadImage(void)]");
		exit(GAME_FATAL_ERROR);
	}
	return SDL_DisplayFormat(image);
}
