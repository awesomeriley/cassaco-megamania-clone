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
#include "megamania_utils.h"
#include "log.h"
#include <string>

static SDL_TimerID timerID = NULL;

namespace Megamania
{
	/**
	 * Construtor default que cria um novo objeto SplashScreen 
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 */
	SplashScreen::SplashScreen(SDL_Surface *screen)throw(SDLVideoException)
	{   
		if(screen == NULL) {
			throw SDLVideoException("SDL Video não inicializado");
		}
		this->screen = screen;
		icon = LoadImage(PATH_ICON_IMAGE);
		logo = LoadImage(PATH_LOGO_IMAGE);
		msg = LoadImage(PATH_MSG_IMAGE);
		SDL_WM_SetCaption(SPLASH_SCREEN_TITLE, NULL);
		SDL_WM_SetIcon(icon, NULL);
		stfSound = new SDL_Sound();
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
		delete stfSound;
	}

	/**
	 * Função que retorna uma referencia para o logo
	 * da tela Splash Screen
	 *
	 * SDL_Surface -> retorna a referencia para o logo
	 *
	 */
	SDL_Surface * SplashScreen::GetMsg(void)const 
	{
		return this->msg;
	}

	/**
	 * Função que retorna uma referencia para o som
	 * da tela Splash Screen
	 *
	 * SDL_Sound -> retorna a referencia para o som
	 *
	 */
	SDL_Sound * SplashScreen::GetSound(void)const 
	{    
		return this->stfSound;
	}

	Uint32 TimerCallback(Uint32 interval, void* param) 
	{	
		SDL_Rect rect;
		SplashScreen *splash = (SplashScreen *)param;
		SDL_Surface *msg = splash->GetMsg();
		rect.x = (screen->w >> 1) - (msg->w >> 1);
		rect.y = (screen->h >> 1) + (msg->h) + (msg->h);
		SDL_Rect clipRect;
		clipRect.x = rect.x;
		clipRect.y = rect.y;
		clipRect.w = msg->w;
		clipRect.h = msg->h;
		SDL_SetClipRect(screen, &clipRect);
	#if 0 
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
	#endif
		Uint32 initialTime = SDL_GetTicks();
		Uint32 timeSlice = 0;
		splash->GetSound()->Play();
		for(register int i = 0; i <= 0xff; i += 3) {    //255
			SDL_SetAlpha(msg, SDL_SRCALPHA, i);
			SDL_BlitSurface(msg, NULL, screen, &rect);
			SDL_Flip(screen);       
			timeSlice = SDL_GetTicks() - initialTime;
			if(timeSlice < 0) {
				timeSlice = 0;
			}
			SDL_Delay((timeSlice < TIME_PER_TICKS) ? 
					  (TIME_PER_TICKS - timeSlice) :
					   TIME_PER_TICKS);
			timeSlice = initialTime;
		}	    		
		SDL_RemoveTimer(timerID);    //cancela o timer para que não entre um loop infinito
		timerID = NULL;
		return TIME_DELAY;
	}

	void SplashScreen::Show(void) 
	{
		stfSound->Load(PATH_FILE_AUDIO);
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
		/**
		 * Devemos iniciar o sistema Timer aqui, por que se a mesma
		 * for iniciada em outra THREAD, a função de callback não é
		 * chamada
		 */
		if(SDL_WasInit(SDL_INIT_VIDEO) != 0) {
			if(SDL_InitSubSystem(SDL_INIT_TIMER) == -1) {
				LOG_DEBUG(SDL_GetError());  
				LOG_ERROR("Erro ao iniciar Timer Subsystem\n");
				exit(EXIT_FAILURE);        
			}
		}	
		timerID = SDL_AddTimer(TIME_DELAY, TimerCallback, this);	
		if(timerID == NULL) {
			LOG_DEBUG("Erro ao criar TIMER");
		}	
		for(;;) {
			if((SDL_PollEvent(&event)) != 0) {
				if((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE)) {
					SDL_QuitSubSystem(SDL_INIT_TIMER);
					break;
				} 
			}		
		}    
	}
}