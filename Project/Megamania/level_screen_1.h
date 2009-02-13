/***************************************************************
 * Classe que representa a tela da primeira fase do jogo 
 * Megamania, esta fase � composta por 15 naves inimigas que
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __LEVEL_SCREEN_1_H__
#define __LEVEL_SCREEN_1_H__

#include "space_ship_1.h"
#include "abstract_level.h"

namespace Megamania
{
	class LevelScreen : public AbstractLevel
	{
		public:
			LevelScreen(SDL_Surface *)throw(SDLVideoException);
			void Init(void);
	};
}

#endif //__LEVEL_SCREEN_1_H__