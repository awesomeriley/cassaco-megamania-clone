/*******************************************************************************
 * Classe responsavel por controlar toda a lógica do JOGO, está classe
 * é responsavel por inicializar todos os sistemas do SDL, capturar todos
 * os eventos e controlar a logica do jogo, como atualização de tela,
 * atualização de NPC etc.
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
	 * Inicialização do Singleton da classe
	 */
	GameController * GameController::singleton = NULL;

	/*******************************************************************************
	 * Construtor padrão responsavel por inicializar todas as configurações
	 * necessarias a execução do JOGO
	 *
	 *******************************************************************************/
	GameController::GameController(void) 
	{
		width = WIDTH_SCREEN;
		height = HEIGHT_SCREEN;
		running = false;
		splashScreen = new SplashScreen(screen);
		currentScreen = dynamic_cast<AbstractScreen *>(splashScreen);
	}			

	/*******************************************************************************
	 * Função que inicializa todas os subsistemas da biblioteca SDL e set como 
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
	 * Função responsavel por parar a execução do gerenciador de eventos
	 *******************************************************************************/
	void GameController::OnGameStop(void)
	{
		running = false;
	}

	/*******************************************************************************
	 * Função que representa o loop principal para o tratamento de todos os eventos
	 * disparados pelo SDL, esta função irá notificar o objeto interessado nos 
	 * eventos atuais
	 *
	 *******************************************************************************/
	void GameController::OnGameLoop(void) 
	{		
		while(running) {
			if(SDL_PollEvent(&event) != 0) {
				switch(event.type) {
					case SDL_USEREVENT: 
						switch(event.user.code) {
							case SPLASH_SCREEN_FINISH_EVENT:
								InitMenuScreen();
								break;
						}
						break;
					default:
						currentScreen->Event(&event);
						break;
				}				
			} 
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
}