/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase � composta por 15 naves inimigas que
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
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	LevelScreen1::LevelScreen1(SDL_Surface *screen)throw(SDLVideoException) : AbstractLevel(screen){}

	/***************************************************************
	 * Fun��o responsavel por iniciar a posi��o de todas as naves
	 * inimigas e tambem a posi��o da nave Megamania
	 *
	 **************************************************************/
	void LevelScreen1::Init() 
	{
		levelFinishEvent = LEVEL1_FINISH_EVENT;
		levelComplete = false;
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
		//megamania->SetPosition(WIDTH_SCREEN >> 1, static_cast<int>(static_cast<float>(HEIGHT_SCREEN) / 1.4));
		megamania->SetPosition(WIDTH_SCREEN >> 1, hud->GetRect().y - megamania->GetHeightFrame());
		megamania->SetFrame(2);		
		Draw();
		hud->Full();

	}
}
