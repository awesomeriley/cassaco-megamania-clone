/***************************************************************
 * Implementação da classe MenuScreen responsavel por 
 * exibir o menu de opções do jogo.
 * Atualmente este menu apresenta as opções:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com) 
 *
 **************************************************************/
#include "menu_screen.h"
#include "megamania_utils.h"
#include "log.h"
#include <string>
#include "user_event_type.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto MenuScreen 
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	MenuScreen::MenuScreen(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		Init();
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela MenuScreen
	 *
	 **************************************************************/
	MenuScreen::~MenuScreen() 
	{    
		Clear();
	}

	/***************************************************************
	 * Função responsavel por inicializar a classe corretamente
	 * carregando todas as surfaces e setando o titulo corretamente
	 *
	 **************************************************************/
	void MenuScreen::Init() 
	{
		int x = MENU_BUTTON_X;
		int y = MENU_BUTTON_Y;
		int vSpace = MENU_BUTTON_VERTICAL_SPACE;
		background = LoadImage(MENU_BACKGROUND);
		startBT   = new CSButton(MENU_BUTTON, x, y);
		scoreBT   = new CSButton(MENU_BUTTON, x, y + vSpace);
		optionsBT = new CSButton(MENU_BUTTON, x, y + (vSpace << 1));               // vSpace * 2
		creditsBT = new CSButton(MENU_BUTTON, x, y + ((vSpace << 1) + vSpace));    // vSpace * 3
		SDL_Font *font = new SDL_Font(MENU_FONT, MENU_BUTTON_FONT_SIZE);
		startBT->SetFont(font);
		scoreBT->SetFont(font);
		optionsBT->SetFont(font);
		creditsBT->SetFont(font);
		startBT->SetText(MENU_START_LABEL);
		scoreBT->SetText(MENU_SCORE_LABEL);
		optionsBT->SetText(MENU_OPTIONS_LABEL);
		creditsBT->SetText(MENU_CREDITS_LABEL);				
	}

	/***************************************************************
	 * Função de callback chamada pelo gerenciador de eventos, esta
	 * função representa o ponto de entrada para o tratamento da 
	 * da lógica da classe	
	 *
	 **************************************************************/
	void MenuScreen::Event(SDL_Event *event) 
	{
		if(startBT->FireChangeImageEvent(event)) {
			event->type = SDL_USEREVENT;
			event->user.code = MENU_SCREEN_FINISH_EVENT;
			SDL_PushEvent(event);
		}
		
		scoreBT->FireChangeImageEvent(event);
		optionsBT->FireChangeImageEvent(event);
		creditsBT->FireChangeImageEvent(event);
	}

	/***************************************************************
	 * Função responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void MenuScreen::Draw(void) 
	{
		startBT->Draw(background);
		scoreBT->Draw(background);		
		optionsBT->Draw(background);		
		creditsBT->Draw(background);		
		SDL_BlitSurface(background, NULL, screen, NULL);
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Função responsavel por desalocar todos os recursos alocados
	 * pela tela, esta funçao deverá ser chamada por ultimo
	 *
	 **************************************************************/
	void MenuScreen::Clear(void) 
	{
		SDL_FreeSurface(this->background);
		delete startBT;
		delete scoreBT;
		delete optionsBT;
		delete creditsBT;
	}

	/***************************************************************
	 * Função responsavel por exibir a tela 
	 *
	 **************************************************************/
	void MenuScreen::Execute(void) 
	{
		Draw();		
	}
}
