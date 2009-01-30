/*************************************************************
 * Arquivo que contém varias operações comuns utilizadas pelo
 * projeto MEGAMANIA, aqui são definidos todas as funções	 
 * relacionadas com carregamento de imagens, manipulação de  
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
 * Função responsavel por carregar o icone do Jogo, a imagem 
 * de logo e a mensagem a ser exibida						 
 *************************************************************/
SDL_Surface * LoadImage(const char *file) 
{    
    SDL_Surface *image = NULL;
	if((image = IMG_Load(file)) == NULL) {
	    LOG_ERROR("Erro ao carregar imagen [LoadImage(const char*)]");
		exit(GAME_FATAL_ERROR);
	}
	return SDL_DisplayFormat(image);
}

/*************************************************************
 * Função para escrever um texto em uma superficie de acordo  
 * com a fonte passada				
 *************************************************************/
SDL_Surface * WriteText(SDL_Surface *surface, TTF_Font *font, SDL_Color color, const char* text) {
	
	if(surface == NULL || font == NULL || text == NULL) {
		LOG_ERROR("Null Pointer. [WriteText(SDL_Surface *, TTF_Font *, SDL_Color, const char *)]");
		exit(GAME_FATAL_ERROR);
	}

	SDL_Surface *txtSurface = TTF_RenderText_Solid(font, text, color);
	txtSurface->clip_rect.h = surface->clip_rect.h;
	txtSurface->clip_rect.w = surface->clip_rect.w;
	txtSurface->clip_rect.x = surface->clip_rect.x;
	txtSurface->clip_rect.y = surface->clip_rect.y;
	SDL_BlitSurface(txtSurface, NULL, surface, NULL);

	//delete txtSurface;
	return surface;
}