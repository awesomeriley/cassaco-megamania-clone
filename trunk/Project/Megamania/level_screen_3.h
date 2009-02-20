/***************************************************************
 * Classe que representa a tela da terceira fase do jogo 
 * Megamania, esta fase é composta por 15 naves inimigas 
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __LEVEL_SCREEN_3_H__
#define __LEVEL_SCREEN_3_H__

#include "space_ship_3.h"
#include "abstract_level.h"

namespace Megamania
{
	class LevelScreen3 : public AbstractLevel
	{
		public:
			LevelScreen3(SDL_Surface *)throw(SDLVideoException);
			void Init(void);
	};
}

#endif //__LEVEL_SCREEN_3_H__