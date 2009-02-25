/***************************************************************
 * Classe que representa a tela da segunda fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com) 
 *
 ***************************************************************/
#include "level_screen_2.h"
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
	LevelScreen2::LevelScreen2(SDL_Surface *screen)throw(SDLVideoException) : AbstractLevel(screen)
	{
		SpaceShip2 *spaceShip = NULL;
		SetShipCount(LEVEL_2_NUMBER_SHIPS);
		for(Uint32 i = 0; i < shipCount; ++i) {
			spaceShip = new SpaceShip2();
			enemies.push_back(spaceShip);
			spaceShip = NULL;
		}
		levelFinishEvent = LEVEL2_FINISH_EVENT;
	}

	/***************************************************************
	 * Função responsavel por iniciar a posição de todas as naves
	 * inimigas e tambem a posição da nave Megamania
	 *
	 **************************************************************/
	void LevelScreen2::Init() 
	{
		Enemy *space = NULL;
		int w = WIDTH_SCREEN;
		int h = HEIGHT_SCREEN;
		int lRow = LEVEL_2_SHIPS_ROW;
		int lCol = LEVEL_2_SHIPS_COL;
		int offset_x = w / lRow;		
		int offset_y = (SPACE_SHIP_2_HEIGHT << 1) + SPACE_SHIP_2_HEIGHT;
		for(Uint32 i = 0; i < lRow; ++i) {
			for(Uint32 j = 0; j < lCol; ++j) {
				space = reinterpret_cast<Enemy *>(enemies[i * lCol + j]);
				space->SetVisible(true);
				if((i & 1) == 0) {    //i % 2
					space->SetPosition(j * offset_x + (i * offset_x), i * offset_y - ((h >> 1) + offset_y));
				} else {
					space->SetPosition(j * offset_x - (i * offset_x), i * offset_y - ((h >> 1) + offset_y));
				}				
				enemies.push_back(space);
			}
		}		
		AbstractLevel::Init();	
	}
}