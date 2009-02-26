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
		currentScreen = new SplashScreen(screen);
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
		SDL_EnableKeyRepeat(REPEAT_DELAY, REPEAT_INTERVAL);
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
							case LEVEL1_FINISH_EVENT:
							case LEVEL2_FINISH_EVENT:
							case LEVEL3_FINISH_EVENT:
								InitLevel(event.user.code);
								break;
						}
						break;
					default:
						currentScreen->Event(&event);
						break;
				}				
			} 
			currentTimer = SDL_GetTicks() - lastTimer;
			if(currentTimer < 0) {
				currentTimer = 0;
			}
			SDL_Delay(currentTimer < TIME_PER_TICKS ? 
					  TIME_PER_TICKS - currentTimer: TIME_PER_TICKS);
			lastTimer = currentTimer;			
			currentScreen->Draw();
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
		currentScreen->Execute();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitMenuScreen(void) 
	{
		delete currentScreen;
		screen->clip_rect.x = screen->clip_rect.y = 0;
		screen->clip_rect.w = WIDTH_SCREEN;
		screen->clip_rect.h = HEIGHT_SCREEN;
		currentScreen = new MenuScreen(screen);
		currentScreen->Execute();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::LoadGame(void) {
	
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitLevel(int code) 
	{		
		if(currentScreen != NULL) {
			delete currentScreen;
		}
		switch(event.user.code) {
			case MENU_SCREEN_FINISH_EVENT:
				currentScreen = new LevelScreen1(screen);
				break;
			case LEVEL1_FINISH_EVENT:
				currentScreen = new LevelScreen2(screen);
				break;
			case LEVEL2_FINISH_EVENT:
				currentScreen = new LevelScreen3(screen);
				break;
			case LEVEL3_FINISH_EVENT:
				currentScreen = new LevelScreen1(screen);
				break;
		}		
		(reinterpret_cast<AbstractLevel *>(currentScreen))->SetMegamania(megamania);
		currentScreen->Init();
		currentScreen->Execute();		
	}
}