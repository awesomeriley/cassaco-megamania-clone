/******************************************************************
 * Arquivo que define a interface publica para a classe 
 * MenuScreen MenuScreen responsavel por 
 * exibir o menu de op��es do jogo.
 * Atualmente este menu apresenta as op��es:
 * Start, Options, High Score, Credits
 *
 * Author Marcelo Collyer (marcelocollyer@gmail.com)
 * 
 *****************************************************************/
#ifndef __MENU_SCREEN_H__
#define __MENU_SCREEN_H__

#include "SDL.h"
#include "cs_button.h"
#include "sdl_font.h"
#include "game_config.h"
#include "abstract_screen.h"
#include "video_exception.h"

namespace Megamania
{
	class MenuScreen : public AbstractScreen
	{
		private:
			/** surface que indica o background do JOGO*/
			SDL_Surface *background;
			/** Bot�o responsavel por iniciar um novo JOGO*/
			CSButton *startBT;
			/** Bot�o responsavel por abrir a tela de op��es*/
			CSButton *optionsBT;
			/** Bot�o responsavel por abrir a tela de Score*/
			CSButton *scoreBT;
			/** Bot�o responsavel por abrir a tela de creditos*/
			CSButton *creditsBT;									
		public:
			MenuScreen(SDL_Surface *)throw(SDLVideoException);
			~MenuScreen(void);
			void Init(void);
			void Execute(void);
			void Event(SDL_Event *);
            void Draw(void);
			void Clear(void);
	};
}

#endif //__MENU_SCREEN_H__