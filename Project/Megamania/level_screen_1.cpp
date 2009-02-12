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
	 * Função responsavel por iniciar a posição de todas as naves
	 * inimigas e tambem a posição da nave Megamania
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
					space->SetPosition(j * offset_x - WIDTH_SCREEN, (i + 1) * offset_y);
				} else {
					space->SetPosition(j * offset_x + (offset_x >> 1) - WIDTH_SCREEN, (i + 1) * offset_y);
				}				
				enemies.push_back(space);
			}
		}

		megamania = new Ship(MEGAMANIA, MEGAMANIA_WIDTH, MEGAMANIA_HEIGHT);
		megamania->SetPosition(WIDTH_SCREEN >> 1, static_cast<int>(static_cast<float>(HEIGHT_SCREEN) / 1.4));
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
		megamania->Event(event);
	}

	/***************************************************************
	 * Função responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void LevelScreen::Draw(void) 
	{
		SpaceShip1 *space= NULL;
		int randomShootShipNumber = 1 + rand() % 10;

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		Bullet &bullet = megamania->GetBullet();
		Bullet *spaceBullet = NULL;
		for(Uint32 i = 0; i < LEVEL_1_NUMBER_SHIPS; ++i) {
			space = dynamic_cast<SpaceShip1 *>(enemies[i]);
			if(space->IsVisible()) {
				if(i == randomShootShipNumber && !space->GetBullet().IsVisible()){
					space->Shoot();
				}		
				space->Draw(screen);
				space->NextFrame();
				space->Update();
				spaceBullet = &space->GetBullet();

				if(spaceBullet->IsVisible() && megamania->IsVisible() && megamania->CollidesWith(*spaceBullet)){
					megamania->SetVisible(false);
					spaceBullet->SetVisible(false);
				}

				if((bullet.IsVisible())&&(space->CollidesWith(bullet))) {
					space->SetVisible(false);
					bullet.SetVisible(false);
				}
			}
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
