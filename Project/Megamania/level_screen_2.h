/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas que
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