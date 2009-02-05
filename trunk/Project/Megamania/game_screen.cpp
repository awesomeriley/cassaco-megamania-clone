/***************************************************************
 * Implementação da classe GameScreen responsavel por 
 * exibir o game de opções do jogo.
 * Atualmente este game apresenta as opções:
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
	 * associando o mesmo com a Tela da aplicação
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
	 * Função responsavel por inicializar a classe corretamente
	 * carregando todas as surfaces e setando o titulo corretamente
	 *
	 **************************************************************/
	void GameScreen::Init() 
	{
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
		SetIcon(PATH_ICON_IMAGE);
	}

	/***************************************************************
	 * Função de callback chamada pelo gerenciador de eventos, esta
	 * função representa o ponto de entrada para o tratamento da 
	 * da lógica da classe	
	 *
	 **************************************************************/
	void GameScreen::Event(SDL_Event *event) 
	{
	}

	/***************************************************************
	 * Função responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void GameScreen::Draw(void) 
	{
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Função responsavel por desalocar todos os recursos alocados
	 * pela tela, esta funçao deverá ser chamada por ultimo
	 *
	 **************************************************************/
	void GameScreen::Clear(void) 
	{
		SDL_FreeSurface(this->background);
	}

	/***************************************************************
	 * Função responsavel por exibir a tela 
	 *
	 **************************************************************/
	void GameScreen::Execute(void) 
	{
		Draw();		
	}
}
