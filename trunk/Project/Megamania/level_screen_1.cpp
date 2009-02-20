/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas que
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#include "level_screen_1.h"
#include "user_event_type.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto LevelScreen
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	LevelScreen1::LevelScreen1(SDL_Surface *screen)throw(SDLVideoException) : AbstractLevel(screen)
	{
		SpaceShip1 *spaceShip = NULL;
		for(Uint32 i = 0; i < LEVEL_1_NUMBER_SHIPS; ++i) {
			spaceShip = new SpaceShip1();
			enemies.push_back(spaceShip);
			spaceShip = NULL;
		}
		levelFinishEvent = LEVEL1_FINISH_EVENT;
		levelComplete = false;
	}

	/***************************************************************
	 * Função responsavel por iniciar a posição de todas as naves
	 * inimigas e tambem a posição da nave Megamania
	 *
	 **************************************************************/
	void LevelScreen1::Init() 
	{
		Enemy *space = NULL;
		int w = WIDTH_SCREEN;
		int lRow = LEVEL_1_SHIPS_ROW;
		int lCol = LEVEL_1_SHIPS_COL;
		int offset_x = w / lCol + SPACE_SHIP_1_WIDTH / lCol;		
		int offset_y = SPACE_SHIP_1_HEIGHT + (SPACE_SHIP_1_HEIGHT >> 1);
		for(Uint32 i = 0; i < lRow; ++i) {
			for(Uint32 j = 0; j < lCol; ++j) {
				space = reinterpret_cast<Enemy *>(enemies[i * lCol + j]);
				space->SetVisible(true);
				if((i & 1) == 0) {    //i % 2
					space->SetPosition(j * offset_x - w, (i + 1) * offset_y);
				} else {
					space->SetPosition(j * offset_x + (offset_x >> 1) - w, (i + 1) * offset_y);
				}								
			}
		}		
		space = NULL;
		AbstractLevel::Init();
	}
}
