/********************************************************************
 * Arquivo que contém todas os tipos de eventos definidos para o 
 * jogo, aqui são definidos os eventos que podem ocorrer durante a 
 * execução do Game
 *
 *  Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ********************************************************************/
#ifndef __USER_EVENT_TYPE_H__
#define __USER_EVENT_TYPE_H__

#include "SDL.h"

const static Uint8 SPLASH_SCREEN_FINISH_EVENT = 0x00000001;
const static Uint8 MENU_SCREEN_FINISH_EVENT   = 0x00000002;
const static Uint8 LEVEL1_FINISH_EVENT		  = 0x00000003;
const static Uint8 LEVEL2_FINISH_EVENT		  = 0x00000004;
const static Uint8 LEVEL3_FINISH_EVENT		  = 0x00000005;

#endif //__USER_EVENT_TYPE_H__