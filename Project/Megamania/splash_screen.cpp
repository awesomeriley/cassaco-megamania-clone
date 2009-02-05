/*****************************************************************
 * Arquivo que define a interface publica para a classe 
 * SplashScreen responsavel por somente exibir o logo da
 * empresa por alguns segundos e depois direcionar para a
 * a pr�xima tela
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 * 
 ****************************************************************/
#include "splash_screen.h"
#include "megamania_utils.h"
#include "game_controller.h"
#include "log.h"
#include "user_event_type.h"

/** objeto global para o tratamento de eventos*/
extern SDL_Event event;
/** referencia externa para o timerID gerado quando timer � iniciado*/
static SDL_TimerID timerID = NULL;

/** 
 * flag responsavel por indicar se a anima��o j� iniciou ou
 * n�o, caso j� tenha iniciado ent�o n�o podemos para-la no
 * meio, teremos que esperar terminar a execu��o
 */
static bool hasInit = false;


/*****************************************************************
 * Fun��o que representa a fun��o de callback que ser� chamada
 * ap�s o tempo definido no timer expirar.
 * Esta fun��o somente exibe o logo da empresa e toca um efeito
 * sonoro
 *
 *****************************************************************/
Uint32 TimerCallback(Uint32, void*);

namespace Megamania
{

   /*****************************************************************
	* Fun��o que representa a fun��o de callback que ser� chamada
	* ap�s o tempo definido no timer expirar.
	* Esta fun��o somente exibe o logo da empresa e toca um efeito
	* sonoro
	*
	*****************************************************************/
	Uint32 TimerCallback(Uint32 interval, void* param) 
	{		
		hasInit = true;
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
		event.type = SDL_USEREVENT;
		event.user.code = SPLASH_SCREEN_FINISH_EVENT; 
		SDL_PushEvent(&event);
		timerID = NULL;
		SDL_QuitSubSystem(SDL_INIT_TIMER);    
		return TIME_DELAY;
	}

	/***************************************************************
	 * Construtor default que cria um novo objeto SplashScreen 
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	SplashScreen::SplashScreen(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		Init();
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela SplashScreen
	 *
	 **************************************************************/
	SplashScreen::~SplashScreen() 
	{    
		Clear();
	}

	/***************************************************************
	 * Fun��o que retorna uma referencia para o logo
	 * da tela Splash Screen
	 *
	 * SDL_Surface -> retorna a referencia para o logo
	 *
	 **************************************************************/
	SDL_Surface * SplashScreen::GetMsg(void)const 
	{
		return this->msg;
	}

	/***************************************************************
	 * Fun��o que retorna uma referencia para o som
	 * da tela Splash Screen
	 *
	 * SDL_Sound -> retorna a referencia para o som
	 *
	 **************************************************************/
	SDL_Sound * SplashScreen::GetSound(void)const 
	{    
		return this->stfSound;
	}

	/***************************************************************
	 * Fun��o responsavel por inicializar a classe corretamente
	 * carregando todas as surfaces e setando o titulo corretamente
	 *
	 **************************************************************/
	void SplashScreen::Init() 
	{
		logo = LoadImage(PATH_LOGO_IMAGE);
		msg = LoadImage(PATH_MSG_IMAGE);
		stfSound = new SDL_Sound();		
	}

	/***************************************************************
	 * Fun��o de callback chamada pelo gerenciador de eventos, esta
	 * fun��o representa o ponto de entrada para o tratamento da 
	 * da l�gica da classe	
	 *
	 **************************************************************/
	void SplashScreen::Event(SDL_Event *event) 
	{
		if((event->key.keysym.sym == SDLK_ESCAPE)&&(!hasInit)) {
			SDL_QuitSubSystem(SDL_INIT_TIMER);
			event->type = SDL_USEREVENT;
			event->user.code = SPLASH_SCREEN_FINISH_EVENT;
			SDL_PushEvent(event);
		}
	}

	/***************************************************************
	 * Fun��o responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void SplashScreen::Draw(void) 
	{
	}

	/***************************************************************
	 * Fun��o responsavel por desalocar todos os recursos alocados
	 * pela tela, esta fun�ao dever� ser chamada por ultimo
	 *
	 **************************************************************/
	void SplashScreen::Clear(void) 
	{
		SDL_FreeSurface(this->msg);
		SDL_FreeSurface(this->logo);
		this->screen = NULL;
		delete stfSound;
	}

	/***************************************************************
	 * Fun��o responsavel por exibir a tela 
	 *
	 **************************************************************/
	void SplashScreen::Execute(void) 
	{
		stfSound->Load(PATH_FILE_AUDIO);
		Uint32 wColor = 0xff;
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, wColor, wColor, wColor));
		SDL_Rect rect;	
		rect.w = logo->w;
		rect.h = logo->h;
		rect.x = (screen->w >> 1) - (rect.w  >> 1);
		rect.y = (screen->h >> 1) - (rect.h  >> 1);
		SDL_BlitSurface(logo, NULL, screen, &rect);
		SDL_Flip(screen);
		timerID = SDL_AddTimer(TIME_DELAY, TimerCallback, this);	
		if(timerID == NULL) {
			LOG_DEBUG("Erro ao criar TIMER");
		}			
	}
}