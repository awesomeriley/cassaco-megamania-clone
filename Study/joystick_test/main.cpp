
#include "SDL.h"
#include <stdlib.h>
#include <stdio.h>

#define MILLIS_PER_TICK 30
#define WIDTH 640
#define HEIGHT 480

static SDL_Surface *screen = NULL;
static SDL_Surface *ball = NULL;
static SDL_Event event;
static SDL_Joystick *joystick = NULL;
static int nStickButtons = 0;
static int nStickAxis = 0;
static int lastTime = 0;
static int currentTime = 0;
int x = 0;
int y = 0;
const static int offset = 5;

int main(int argc, char **argv) {
	
	FILE *debug = NULL;
	atexit(SDL_Quit);
	SDL_Init(SDL_INIT_EVERYTHING);
	if((debug = fopen("debug.txt", "a")) == NULL) {
		exit(EXIT_FAILURE);
	}
	if((screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, SDL_SWSURFACE|SDL_DOUBLEBUF)) == NULL) {
		fprintf(debug, "Erro ao criar surface\n");
		exit(EXIT_FAILURE);
	}
	if((ball = SDL_LoadBMP("ball.bmp")) == NULL) {
		fprintf(debug, "Erro ao criar ball\n");
		exit(EXIT_FAILURE);	
	}
	SDL_JoystickEventState(SDL_ENABLE);
	if(SDL_NumJoysticks()) {
		joystick = SDL_JoystickOpen(0);
		nStickButtons = SDL_JoystickNumButtons(joystick);
		nStickAxis = SDL_JoystickNumAxes(joystick);
		if((nStickButtons >= 2)&&(nStickAxis >= 2)) {
			fprintf(debug, "Nome joystick: %s\n", SDL_JoystickName(0));
			SDL_SetColorKey(ball, SDL_SRCCOLORKEY, SDL_MapRGB(ball->format, 0, 0, 0));			
			ball->clip_rect.x = x = (screen->clip_rect.w >> 1) - (ball->clip_rect.w >> 1);
			ball->clip_rect.y = y = (screen->clip_rect.h >> 1) - (ball->clip_rect.h >> 1);
			SDL_BlitSurface(ball, NULL, screen, &ball->clip_rect);
			SDL_Flip(screen);
			bool running = true;
			SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
			lastTime = SDL_GetTicks();
			while(running) {
				while(SDL_PollEvent(&event)) {
					if((event.type == SDL_QUIT)||((event.type == SDL_KEYDOWN)&&(event.key.keysym.sym == SDLK_ESCAPE))) {
						running = false;
					}
					if(event.type == SDL_JOYAXISMOTION) {
						if(event.jaxis.axis == 0) {
							if((event.jaxis.value > -8000)&&(event.jaxis.value < 8000)) {	
								x = 0;
							} else {						
								if(event.jaxis.value < 0) {
									if(ball->clip_rect.x - offset < 0) {
										x = 0;
									} else  {										
										x = -offset;
									}									
								} else {
									if((ball->clip_rect.x + offset) >= WIDTH -  ball->clip_rect.w) {
										x = 0;
									} else {
										x = offset;
									}							
								}
							}
						} else {
							if((event.jaxis.value > -8000)&&(event.jaxis.value < 8000)) {	
								y = 0;
							} else {						
								if(event.jaxis.value < 0) {
									if(ball->clip_rect.y - offset < 0) {
										y = 0;
									} else  {										
										y = -offset;
									}									
								} else {
									if((ball->clip_rect.y + offset) >= HEIGHT -  ball->clip_rect.h) {
										y = 0;
									} else {
										y = offset;
									}							
								}
							}
						}	
					}										
				}				
				ball->clip_rect.x += x;
				ball->clip_rect.y += y;
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
				SDL_BlitSurface(ball, NULL, screen, &ball->clip_rect);
				SDL_Flip(screen);
				currentTime = SDL_GetTicks() - lastTime;
				if(currentTime < MILLIS_PER_TICK) {
					if(currentTime < 0) {
					    currentTime = 0;
					}
					SDL_Delay(MILLIS_PER_TICK - currentTime);
				} else {
					SDL_Delay(MILLIS_PER_TICK);
				}
				lastTime = currentTime;
			}
		}
	} else {
		fprintf(debug, "Nenhum joystick anexado\n");
	}
	SDL_JoystickClose(joystick);
	return EXIT_SUCCESS;
}