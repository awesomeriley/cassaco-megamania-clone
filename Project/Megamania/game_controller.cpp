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
	 * 
	 *******************************************************************************/
	void GameController::OnGameInit(void) 
	{
		Initializer::Init();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::OnGameEvent(SDL_Event *event)
	{			
		switch(event->type) {
			case SDL_USEREVENT:
				switch(event->user.code) {
					case SPLASH_SCREEN_ID_EVENT:
						InitMenuScreen();
						break;
				}
		}		
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::OnGameStop(void)
	{
		running = false;
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::OnGameExit(void)
	{
		Initializer::Shutdow();
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::OnGameDraw(void)
	{
	}
	
	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitSpashScreen(void) 
	{
		splashScreen->Show();		
	}

	/*******************************************************************************
	 * 
	 *******************************************************************************/
	void GameController::InitMenuScreen(void) 
	{
		menuScreen->Show();
	}
}