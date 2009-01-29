/**
 * Arquivo que define a interface publica para a classe 
 * CSButton que � a representa��o de um bot�o baseado 
 * em interfaces GUI.
 *
 * Author Marcelo Costa Collyer (marcelocollyer@gmail.com) 
 *
 */
#ifndef __CSBUTTON_H__
#define __CSBUTTON_H__

#include "SDL.h"
#include "game_config.h"
#include "video_exception.h"

namespace Megamania
{
	class CSButton 
	{
		enum STATE_ENUM {DEFAULT, DOWN, HIGH_LIGHT};
		
		private:
			void ChangeState(char *, STATE_ENUM);
			int x, y;
			char* label;

		public:			
			CSButton(char *, int, int);
			~CSButton(void);
			
			STATE_ENUM state;
			char* downImagePath;
			char* lightImagePath;
			char* defaultImagePath;

			SDL_Surface *surface;
			SDL_Surface *FireChangeImageEvent(SDL_Event*);
			void SetLabel(char*);
	};
}

#endif //__CSBUTTON_H__