/***************************************************************
 * Classe que representa a tela da segunda fase do jogo 
 * Megamania, esta fase � composta por 18 naves inimigas que
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com) 
 *
 ***************************************************************/
#ifndef __LEVEL_SCREEN_2_H__
#define __LEVEL_SCREEN_2_H__

#include "space_ship_2.h"
#include "abstract_level.h"

namespace Megamania
{
	class LevelScreen2 : public AbstractLevel
	{
		public:
			LevelScreen2(SDL_Surface *)throw(SDLVideoException);
			void Init(void);
	};
}

#endif //__LEVEL_SCREEN_2_H__