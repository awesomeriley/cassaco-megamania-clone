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
#include <algorithm>
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
		music = new Music();
		music->Load(PATH_MENU_MUSIC);
 		startBT   = new CSButton(MENU_BUTTON, x, y);
		scoreBT   = new CSButton(MENU_BUTTON, x, y + vSpace);                      // vSpace * 1 
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
		AddListener(startBT);
		AddListener(scoreBT);
		AddListener(optionsBT);
		AddListener(creditsBT);
		music->Play(MIX_PLAY_FOREVER);
	}

	/***************************************************************
	 * Função que adiciona um listener interessado em ouvir os 
	 * eventos da classe, caso seja passado como parametro um
	 * ponteiro NULL, nada ocorrerá
	 *
	 **************************************************************/
	void MenuScreen::AddListener(MenuScreenListener *listener) 
	{
		if(listener != NULL) {
			std::vector<MenuScreenListener *>::const_iterator const_end = listeners.end();
			for(std::vector<MenuScreenListener *>::const_iterator const_iter = listeners.begin(); const_iter != const_end; ++const_iter) {
				if(*const_iter == listener) {
					return;
				}
			}
			listeners.push_back(listener);
		}
	}
	
	/***************************************************************
	 * Função responsavel por remover um listener da classe, caso 
	 * seja informado como parametro um ponteiro NULL ou um listener
	 * não registrado nada ocorrerá
	 *
	 **************************************************************/
	void MenuScreen::RemoveListener(MenuScreenListener *listener) 
	{
		if(listener != NULL) {
			listeners.erase(std::find(listeners.begin(), listeners.end(), listener));
		}
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
		for(int i = listeners.size(); --i >= 0;) {
			listeners[i]->Action(background);		
		}
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
		listeners.clear();
		delete music;
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
