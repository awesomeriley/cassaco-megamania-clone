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
#define TIME_PER_TICKS 30
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
#define MEGAMANIA "spaceship.png"
#define MEGAMANIA_WIDTH 50
#define MEGAMANIA_HEIGHT 85
#define MEGAMANIA_OFFSET 10
#define PATH_SPACE_SHIP_1 "enemy_1.png"
#define SPACE_SHIP_1_WIDTH 50
#define SPACE_SHIP_1_HEIGHT 27
#define SPACE_SHIP_1_OFFSET 8
#define LEVEL_1_NUMBER_SHIPS 15
#define LEVEL_1_SHIPS_ROW 3
#define LEVEL_1_SHIPS_COL 5
#define PATH_BULLET "bullet.png"
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 24
#define BULLET_OFFSET 15
#define REPEAT_DELAY 1
#define REPEAT_INTERVAL 1
#define PATH_BULLET_ENEMY "bullet_2.png"
#define PATH_MENU_MUSIC "loop_menu.ogg"

static SDL_Surface *screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, BPP, SDL_SWSURFACE|SDL_DOUBLEBUF);

#endif //__GAME_H__