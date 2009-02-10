/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas que
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#include "ship.h"
#include "level_screen_1.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto LevelScreen
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	LevelScreen::LevelScreen(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		Init();
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todas as imagens
	 * utilizadas pela SplashScreen
	 *
	 **************************************************************/
	LevelScreen::~LevelScreen() 
	{    
		Clear();
	}

	/***************************************************************
	 *
	 **************************************************************/
	void LevelScreen::Init() 
	{
		int w = WIDTH_SCREEN;
		int lCol = LEVEL_1_SHIPS_COL;
		int offset_x = w / lCol + SPACE_SHIP_1_WIDTH / lCol;		
		int offset_y = SPACE_SHIP_1_HEIGHT + (SPACE_SHIP_1_HEIGHT >> 1);
		for(Uint32 i = 0; i < LEVEL_1_SHIPS_ROW; ++i) {
			for(Uint32 j = 0; j < lCol; ++j) {
				SpaceShip1 *space = new SpaceShip1();
				if((i & 1) == 0) {
					space->SetPosition(j * offset_x, i * offset_y);
				} else {
					space->SetPosition(j * offset_x + (offset_x >> 1), i * offset_y);
				}				
				enemies.push_back(space);
			}
		}

		megamania = new Ship(MEGAMANIA, MEGAMANIA_WIDTH, MEGAMANIA_HEIGHT);
		megamania->SetPosition(WIDTH_SCREEN >> 1, HEIGHT_SCREEN / 1.4);
		megamania->SetFrame(2);
		
	}

	/***************************************************************
	 * Função que representa o ponto de entrada para a execução da 
	 * fase
	 *
	 **************************************************************/
	void LevelScreen::Execute(void) 
	{
		Draw();
	}

	/***************************************************************
	 * Função de callback chamada pelo gerenciador de eventos, esta
	 * função representa o ponto de entrada para o tratamento da 
	 * da lógica da classe	
	 *
	 **************************************************************/
	void LevelScreen::Event(SDL_Event *event) 
	{
		int x = megamania->GetCurrentFrame();
		switch(event->key.keysym.sym){
		
			case SDLK_LEFT:
				megamania->Move(-MEGAMANIA_OFFSET, 0);
				if(x == 1 || x == 2) {
					megamania->PrevFrame();
				}else{
					megamania->SetFrame(1);
				}
				break;

			case SDLK_RIGHT:
				megamania->Move(MEGAMANIA_OFFSET, 0);
				if(x == 2 || x == 3){
					megamania->NextFrame();
				}else{
					megamania->SetFrame(3);
				}
				break;

			default:
				megamania->SetFrame(2);
				break;
		}
	}

	/***************************************************************
	 * Função responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void LevelScreen::Draw(void) 
	{
		SpaceShip1 *space= NULL;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		for(Uint32 i = 0; i < LEVEL_1_NUMBER_SHIPS; ++i) {
			space = dynamic_cast<SpaceShip1 *>(enemies[i]);
			space->Draw(screen);
			space->NextFrame();
			space->Update();
		}		
		
		megamania->Draw(screen);
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Função responsavel por desalocar todos os recursos alocados
	 * pela tela, esta funçao deverá ser chamada por ultimo
	 *
	 **************************************************************/
	void LevelScreen::Clear(void) 
	{
		for(Uint32 i = 0; i < LEVEL_1_NUMBER_SHIPS; ++i) {
			delete enemies[i];
		}
	}
}
