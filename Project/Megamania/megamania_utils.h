/*************************************************************
 * Arquivo que cont�m varias opera��es comuns utilizadas pelo
 * projeto MEGAMANIA, aqui s�o definidos todas as fun��es	 
 * relacionadas com carregamento de imagens, manipula��o de  
 * Strings dentre outras									 
 *															 
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Co-Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
 *************************************************************/
#ifndef __MEGAMANIA_UTILS_H__
#define __MEGAMANIA_UTILS_H__

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "log.h"
#include "game_config.h"

SDL_Surface * LoadImage(const char *file);

/*************************************************************
 * Fun��o para escrever um texto em uma superficie de acordo 
 * com a fonte passada.
 *************************************************************/
SDL_Surface * WriteText(SDL_Surface *, TTF_Font *, SDL_Color, const char*);

#endif //__MEGAMANIA_UTILS_H__