/**
 * Arquivo que cont�m varias opera��es comuns utilizadas pelo
 * projeto MEGAMANIA, aqui s�o definidos todas as fun��es relacionadas
 * com carregamento de imagens, manipula��o de Strings dentre outras
 * 
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#include "megamania_utils.h"

/**
 * Fun��o responsavel por carregar o icone do Jogo, a imagem
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
