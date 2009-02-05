/******************************************************************
 * Arquivo que define a interface publica para a classe 
 * MenuScreen MenuScreen responsavel por 
 * exibir o menu de opções do jogo.
 * Atualmente este menu apresenta as opções:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com)
 * 
 *****************************************************************/
#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__

#include "SDL.h"
#include "cs_button.h"
#include "sdl_font.h"
#include "game_config.h"
#include "abstract_screen.h"
#include "video_exception.h"

namespace Megamania
{
	class GameScreen : public AbstractScreen
	{
		private:
			/** surface que indica o background do JOGO*/
			SDL_Surface *background;
		public:
			GameScreen(SDL_Surface *)throw(SDLVideoException);
			~GameScreen(void);
			void Init(void);
			void Execute(void);
			void Event(SDL_Event *);
            void Draw(void);
			void Clear(void);
	};
}

#endif //__GAME_SCREEN_H__