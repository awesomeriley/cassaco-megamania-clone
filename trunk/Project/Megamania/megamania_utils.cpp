/*************************************************************
 * Arquivo que cont�m varias opera��es comuns utilizadas pelo
 * projeto MEGAMANIA, aqui s�o definidos todas as fun��es	 
 * relacionadas com carregamento de imagens, manipula��o de  
 * Strings dentre outras									 
 *															 
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author: Marcelo Collyer
 * Email : marcelocollyer@gmail.com
 *************************************************************/
#include "megamania_utils.h"
#include "SDL.h"
#include "SDL_ttf.h"

/*************************************************************
 * Fun��o responsavel por carregar o icone do Jogo, a imagem 
 * de logo e a mensagem a ser exibida						 
 *************************************************************/
SDL_Surface * LoadImage(const char *file) 
{    
    SDL_Surface *image = NULL;
	if((image = IMG_Load(file)) == NULL) {
	    LOG_ERROR("Erro ao carregar imagen [LoadImage(void)]");
		exit(GAME_FATAL_ERROR);
	}
	return SDL_DisplayFormat(image);
}

/*************************************************************
 * Fun��o para escrever um texto em uma superficie de acordo  
 * com a fonte passada				
 *************************************************************/
SDL_Surface * WriteText(SDL_Surface *surface, TTF_Font *font, SDL_Color color, const char* text) {
	
	SDL_Surface *txtSurface = TTF_RenderText_Solid(font, text, color);
	SDL_BlitSurface(surface, NULL, txtSurface, NULL);
	delete txtSurface;
	return surface;
}