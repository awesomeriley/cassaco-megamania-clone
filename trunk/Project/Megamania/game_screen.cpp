/***************************************************************
 * Implementa��o da classe GameScreen responsavel por 
 * exibir o game de op��es do jogo.
 * Atualmente este game apresenta as op��es:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com) 
 *
 **************************************************************/
#include "game_screen.h"
#include "megamania_utils.h"
#include "log.h"
#include <string>

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto GameScreen 
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	GameScreen::GameScreen(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		Init();
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela GameScreen
	 *
	 **************************************************************/
	GameScreen::~GameScreen() 
	{    
		Clear();
	}

	/***************************************************************
	 * Fun��o responsavel por inicializar a classe corretamente
	 * carregando todas as surfaces e setando o titulo corretamente
	 *
	 **************************************************************/
	void GameScreen::Init() 
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
		SetIcon(PATH_ICON_IMAGE);
	}

	/***************************************************************
	 * Fun��o de callback chamada pelo gerenciador de eventos, esta
	 * fun��o representa o ponto de entrada para o tratamento da 
	 * da l�gica da classe	
	 *
	 **************************************************************/
	void GameScreen::Event(SDL_Event *event) 
	{
	}

	/***************************************************************
	 * Fun��o responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void GameScreen::Draw(void) 
	{
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Fun��o responsavel por desalocar todos os recursos alocados
	 * pela tela, esta fun�ao dever� ser chamada por ultimo
	 *
	 **************************************************************/
	void GameScreen::Clear(void) 
	{
		SDL_FreeSurface(this->background);
	}

	/***************************************************************
	 * Fun��o responsavel por exibir a tela 
	 *
	 **************************************************************/
	void GameScreen::Execute(void) 
	{
		Draw();		
	}
}
