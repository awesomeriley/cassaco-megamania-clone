/*********************************************************************
 * Arquivo que define todas as configurações do Jogo MEGAMANIA
 * aqui são definidos os caminhos das imagens bem como configurações
 * do jogo
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ********************************************************************/
#ifndef __GAME_H__
#define __GAME_H__

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#ifndef __cplusplus
#error "O projeto deve ser compilado com um compilador C++"
#endif

#define MIX_DEFAULT_CHUNK_BUFFER_SIZE 4096
#define WIDTH_SCREEN 800
#define HEIGHT_SCREEN 600
#define BPP 0    //exibe no formato atual do video
#define GAME_FATAL_ERROR 1
#define TIME_DELAY 2000
#define TIME_PER_TICKS 50
#define GAME_TITLE "Megamania Clone"
#define MENU_START_LABEL "Start"
#define MENU_SCORE_LABEL "High Score"
#define MENU_OPTIONS_LABEL "Options"
#define MENU_CREDITS_LABEL "Credits"
#define PATH_FILE_AUDIO "smell.wav"
#define PATH_ICON_IMAGE "icon.png"
#define PATH_LOGO_IMAGE "logo.png"
#define PATH_MSG_IMAGE "msg.png"
#define MENU_BUTTON "menu_button.png"
#define MENU_BUTTON_MOTION "menu_button_motion.png"
#define MENU_BUTTON_DOWN "menu_button_on.png"
#define MENU_BACKGROUND "menu_background.png"
#define MENU_FONT "matrix.ttf"
#define MENU_BUTTON_FONT_SIZE 30
#define MENU_BUTTON_X 500
#define MENU_BUTTON_Y 250
#define MENU_BUTTON_VERTICAL_SPACE 80
#define SPLASH_SCREEN_ID_EVENT -1    //evita conflitos com os Eventos do SDL

static SDL_Surface *screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, BPP, SDL_SWSURFACE|SDL_DOUBLEBUF);

#endif //__GAME_H__