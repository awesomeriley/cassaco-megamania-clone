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

/** level 1*/
#define PATH_SPACE_SHIP_1 "enemy_1.png"
#define SPACE_SHIP_1_WIDTH 50
#define SPACE_SHIP_1_HEIGHT 25
#define SPACE_SHIP_1_OFFSET_X 8
#define SPACE_SHIP_1_SCORE 20
#define LEVEL_1_NUMBER_SHIPS 15
#define LEVEL_1_SHIPS_ROW 3
#define LEVEL_1_SHIPS_COL 5

/** level 2*/
#define PATH_SPACE_SHIP_2 "enemy_2.png"
#define SPACE_SHIP_2_WIDTH 50
#define SPACE_SHIP_2_HEIGHT 25
#define SPACE_SHIP_2_OFFSET_X 10
#define SPACE_SHIP_2_OFFSET_Y 10
#define SPACE_SHIP_2_SCORE 30
#define LEVEL_2_NUMBER_SHIPS 18
#define LEVEL_2_SHIPS_ROW 6
#define LEVEL_2_SHIPS_COL 3
#define LEVEL_2_DISPLACEMENT_X WIDTH_SCREEN
#define LEVEL_2_DISPLACEMENT_Y 80

/** level 3*/
#define PATH_SPACE_SHIP_3 "enemy_3.png"
#define SPACE_SHIP_3_WIDTH 50
#define SPACE_SHIP_3_HEIGHT 25
#define SPACE_SHIP_3_OFFSET_X 10
#define SPACE_SHIP_3_OFFSET_Y 10
#define SPACE_SHIP_3_SCORE 40
#define LEVEL_3_NUMBER_SHIPS 15
#define LEVEL_3_SHIPS_ROW 3
#define LEVEL_3_SHIPS_COL 5
#define LEVEL_3_DISPLACEMENT_X ((WIDTH_SCREEN) / 4)    //displacement = 200

#define PATH_BULLET "bullet.png"
#define BULLET_WIDTH 8
#define BULLET_HEIGHT 24
#define BULLET_OFFSET 15
#define REPEAT_DELAY 1
#define REPEAT_INTERVAL 1
#define PATH_BULLET_ENEMY "bullet_2.png"
#define PATH_MENU_MUSIC "loop_menu.ogg"
#define PATH_MENU_SELECT "menu_select.wav"
#define PATH_MENU_VALIDATE "menu_validate.wav"
#define PATH_PANEL_HUD "panel.png"
#define PATH_ENERGY_BAR_HUD "enerybar.png"
#define PATH_ENERGY_BAR2_HUD "energybar_2.png"
#define PATH_SHIP_ICON "life_icon.png"
#define PATH_BAR_HUD "bar.png"
#define BAR_POSITION_X 150
#define BAR_POSITION_Y 522
#define BAR_WITDH 600
#define POINT_BY_DECREMENT_HUD 100
#define HUD_FONT MENU_FONT
#define SCORE_FONT_SIZE 40
#define HUD_DELAY 15
#define HUD_DRAW_DELAY	700     // 0.7 sec * 1000 milli
#define EFFECT_HUD "menu_select.wav"
#define INITIAL_LIFE 3

static SDL_Surface *screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, BPP, SDL_SWSURFACE|SDL_DOUBLEBUF);

#endif //__GAME_H__