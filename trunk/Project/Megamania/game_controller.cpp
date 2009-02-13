/*******************************************************************************
 * Classe responsavel por controlar toda a l�gica do JOGO, est� classe
 * � responsavel por inicializar todos os sistemas do SDL, capturar todos
 * os eventos e controlar a logica do jogo, como atualiza��o de tela,
 * atualiza��o de NPC etc.
 *
 *  Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 *******************************************************************************/
#include "game_controller.h"
#include "initializer.h"
#include "user_event_type.h"

namespace Megamania 
{

	/*
	 * Inicializa��o do Singleton da classe
	 */
	GameController * GameController::singleton = NULL;

	/*******************************************************************************
	 * Construtor padr�o responsavel por inicializar todas as configura��es
	 * necessarias a execu��o do JOGO
	 *
	 *******************************************************************************/
	GameController::GameController(void) 
	{
		width = WIDTH_SCREEN;
		height = HEIGHT_SCREEN;
		running = false;
		splashScreen = new SplashScreen(screen);
		currentScreen = dynamic_cast<AbstractScreen *>(splashScreen);
		megamania = new Ship(MEGAMANIA, MEGAMANIA_WIDTH, MEGAMANIA_HEIGHT);
	}			

	/*******************************************************************************
	 * Fun��o que inicializa todas os subsistemas da biblioteca SDL e set como 
	 * tela inicial o SplashScreen
	 *
	 *******************************************************************************/
	void GameController::OnGameInit(void) 
	{
		Initializer::Init();
		InitSpashScreen();
		running = true;
	}

	/*******************************************************************************
	 * Fun��o responsavel por parar a execu��o do gerenciador de eventos
	 *******************************************************************************/
	void GameController::OnGameStop(void)
	{
		running = false;
	}

	/*******************************************************************************
	 * Fun��o que representa o loop principal para o tratamento de todos os eventos
	 * disparados pelo SDL, esta fun��o ir� notificar o objeto interessado nos 
	 * eventos atuais
	 *
	 *******************************************************************************/
	void GameController::OnGameLoop(void) 
	{		
		lastTimer = SDL_GetTicks();
		while(running) {
			if(SDL_PollEvent(&event)) {
				switch(event.type) {
					case SDL_QUIT:
						running = false;
						break;
					case SDL_USEREVENT: 
						switch(event.user.code) {
							case SPLASH_SCREEN_FINISH_EVENT:
								InitMenuScreen();
								break;
							case MENU_SCREEN_FINISH_EVENT:
								InitGameScreen(MENU_SCREEN_FINISH_EVENT);
								break;
							case LEVEL1_FINISH_EVENT:
								InitGameScreen(LEVEL1_FINISH_EVENT);
								break;
						}
						break;
					default:
						currentScreen->Event(&event);
						break;
				}				
			} 
			currentScreen->Draw();
			currentTimer = SDL_GetTicks() - lastTimer;
			if(currentTimer < TIME_PER_TICKS) {
				if(currentTimer < 0) {
					currentTimer = 0;
				}
				SDL_Delay(TIME_PER_TICKS - currentTimer);
			} else {
				SDL_Delay(TIME_PER_TICKS);
			}
			lastTimer = currentTimer;			
		}
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::OnGameExit(void)
	{
		Initializer::Shutdown();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitSpashScreen(void) 
	{
		splashScreen->Execute();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitMenuScreen(void) 
	{
		delete splashScreen;
		screen->clip_rect.x = screen->clip_rect.y = 0;
		screen->clip_rect.w = WIDTH_SCREEN;
		screen->clip_rect.h = HEIGHT_SCREEN;
		menuScreen = new MenuScreen(screen);
		currentScreen = dynamic_cast<AbstractScreen *>(menuScreen);
		menuScreen->Execute();
	}
	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitGameScreen(int completeLevelNumber) 
	{
		delete menuScreen;
		screen->clip_rect.x = screen->clip_rect.y = 0;
		screen->clip_rect.w = WIDTH_SCREEN;
		screen->clip_rect.h = HEIGHT_SCREEN;
		
		switch(completeLevelNumber){
			
			case LEVEL1_FINISH_EVENT:
				//TODO should be level2
				levelScreen = new LevelScreen1(screen);		
				levelScreen->SetShipCount(LEVEL_2_NUMBER_SHIPS);
			default:
				levelScreen = new LevelScreen1(screen);		
				levelScreen->SetShipCount(LEVEL_1_NUMBER_SHIPS);
		}
		
		levelScreen->SetMegamania(megamania);
		SDL_EnableKeyRepeat(REPEAT_DELAY, REPEAT_INTERVAL);
		currentScreen = dynamic_cast<AbstractLevel *>(levelScreen);
		levelScreen->Init();
		levelScreen->Execute();
	}
}