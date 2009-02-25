/***************************************************************
 * Classe que representa a tela da terceira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#include "level_screen_3.h"
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
	LevelScreen3::LevelScreen3(SDL_Surface *screen)throw(SDLVideoException) : AbstractLevel(screen)
	{
		SpaceShip3 *spaceShip = NULL;
		SetShipCount(LEVEL_3_NUMBER_SHIPS);
		for(Uint32 i = 0; i < shipCount; ++i) {
			spaceShip = new SpaceShip3();
			enemies.push_back(spaceShip);
			spaceShip = NULL;
		}		
		levelFinishEvent = LEVEL3_FINISH_EVENT;
	}

	/***************************************************************
	 * Função responsavel por iniciar a posição de todas as naves
	 * inimigas e tambem a posição da nave Megamania
	 *
	 **************************************************************/
	void LevelScreen3::Init() 
	{
		Enemy *space = NULL;
		int w = WIDTH_SCREEN;
		int lRow = LEVEL_3_SHIPS_ROW;
		int lCol = LEVEL_3_SHIPS_COL;
		int offset_x = w / lCol + SPACE_SHIP_3_WIDTH / lCol;		
		int offset_y = SPACE_SHIP_3_HEIGHT + (SPACE_SHIP_3_HEIGHT >> 1);		
		int hLimitSup = HEIGHT_SCREEN / 3 * 2 - SPACE_SHIP_3_HEIGHT;				
		for(Uint32 i = 0; i < lRow; ++i) {
			for(Uint32 j = 0; j < lCol; ++j) {
				space = reinterpret_cast<Enemy *>(enemies[i * lCol + j]);
				space->SetVisible(true);
				if((i & 1) == 0) {    //i % 2
					space->SetPosition(j * offset_x - w, (i + 1) * offset_y);										
				} else {
					space->SetPosition(j * offset_x + (offset_x >> 1) - w, (i + 1) * offset_y);
				}								
				space->GetClipPosition().y = (i + 1) * offset_y;
				space->GetClipPosition().h = hLimitSup - ((lRow - i) * offset_y);
			}
		}		
		space = NULL;
		AbstractLevel::Init();
	}
}
