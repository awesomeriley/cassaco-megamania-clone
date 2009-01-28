/**
 * Arquivo que contém varias operações comuns utilizadas pelo
 * projeto MEGAMANIA, aqui são definidos todas as funções relacionadas
 * com carregamento de imagens, manipulação de Strings dentre outras
 * 
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __MEGAMANIA_UTILS_H__
#define __MEGAMANIA_UTILS_H__

#include "SDL.h"
#include "SDL_image.h"
#include "log.h"
#include "game_config.h"

SDL_Surface * LoadImage(const char *file);

#endif //__MEGAMANIA_UTILS_H__