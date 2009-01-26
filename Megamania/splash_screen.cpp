/**
 * Arquivo que define a interface publica para a classe 
 * SplashScreen responsavel por somente exibir o logo da
 * empresa por alguns segundos e depois direcionar para a
 * a próxima tela
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 * 
 */
#include "splash_screen.h"
#include "log.h"
#include "video_exception.h"
#include <string>

#pragma warning(disable:4297)

/**
 * Construtor default que cria um novo objeto SplashScreen 
 * associando o mesmo com a Tela da aplicação
 *
 * SDL_Surface *screen -> indica a tela do jogo
 * 
 */
SplashScreen::SplashScreen(SDL_Surface *screen)throw() 
{   
	if(screen == NULL) {
		throw SDLVideoException(static_cast<std::string>("SDL Video não inicializado"));
	}
	this->screen = screen;
	icon = LoadImage(PATH_ICON_IMAGE);
	logo = LoadImage(PATH_LOGO_IMAGE);
	msg = LoadImage(PATH_MSG_IMAGE);
	SDL_WM_SetCaption(SPLASH_SCREEN_TITLE, NULL);
	SDL_WM_SetIcon(icon, NULL);
}

/**
 * Destruidor responsavel por desalocar todas as imagens
 * utilizadas pela SplashScreen
 *
 */
SplashScreen::~SplashScreen() 
{    
	SDL_FreeSurface(this->icon);
	SDL_FreeSurface(this->msg);
	SDL_FreeSurface(this->logo);
}

/**
 * Função responsavel por carregar o icone do Jogo, a imagem
 * de logo e a mensagem a ser exibida
 * 
 */
SDL_Surface * SplashScreen::LoadImage(const char *file) 
{    
	SDL_Surface *image = NULL;
	if((image = IMG_Load(file)) == NULL) {
		LOG_ERROR("Erro ao carregar imagen SplashScreen::LoadImage(void)");
		exit(GAME_FATAL_ERROR);
	}
    return SDL_DisplayFormat(image);
}

/**
 * Função que retorna uma referencia para o logo
 * da tela Splash Screen
 *
 * SDL_Surface -> retorna a referencia para o logo
 *
 */
SDL_Surface * SplashScreen::getMsg(void)const 
{
    return this->msg;
}

Uint32 TimerCallback(Uint32 interval, void* param) 
{
	SDL_Rect rect;
	SplashScreen *splash = (SplashScreen *)param;
	SDL_Surface *msg = splash->getMsg();
	rect.x = (screen->w >> 1) - (msg->w >> 1);
	rect.y = (screen->h >> 1) + (msg->h) + (msg->h);
	SDL_Rect clipRect;
	clipRect.x = rect.x;
	clipRect.y = rect.y;
	clipRect.w = msg->w;
	clipRect.h = msg->h;
	SDL_SetClipRect(screen, &clipRect);
#if 0 
	SDL_FillRect(splash_screen, NULL, SDL_MapRGB(splash_screen->format, 0x00, 0x00, 0x00));
#endif
    register int i = 0;
    Uint32 initialTime = SDL_GetTicks();
    Uint32 timeSlice = 0;
	for(; i <= 0xff; i += 3) {    //255
		SDL_SetAlpha(msg, SDL_SRCALPHA, i);
	    SDL_BlitSurface(msg, NULL, screen, &rect);
	    SDL_Flip(screen);       
	    timeSlice = SDL_GetTicks() - initialTime;
		SDL_Delay((timeSlice < TIME_PER_TICKS) ? 
				  (TIME_PER_TICKS - timeSlice) :
		           TIME_PER_TICKS);
	    timeSlice = initialTime;
    }	    		
	return TIME_DELAY;
}

void SplashScreen::Show(void) 
{
    	
	Uint32 wColor = 0xff;
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, wColor, wColor, wColor));
	SDL_Rect rect;
	SDL_Event event;
	rect.w = logo->w;
	rect.h = logo->h;
	rect.x = (screen->w >> 1) - (rect.w  >> 1);
	rect.y = (screen->h >> 1) - (rect.h  >> 1);
	SDL_BlitSurface(logo, NULL, screen, &rect);
	SDL_Flip(screen);
	SDL_TimerID timerID = SDL_AddTimer(TIME_DELAY, TimerCallback, this);	
	if(timerID == NULL) {
		LOG_DEBUG("Erro ao criar TIMER");
	}
	for(;;) {
	    if((SDL_PollEvent(&event)) != 0) {
            if((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE)) {
                SDL_RemoveTimer(timerID);    //cancel the timer
                break;
			} 
        }		
    }    
}