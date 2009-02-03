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
		while(running) {
			if(SDL_PollEvent(&event) != 0) {
				currentScreen->Event(&event);
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
	}
}