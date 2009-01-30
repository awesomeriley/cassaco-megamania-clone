/***************************************************************
 * Arquivo que define a interface publica para a classe 
 * CSButton que é a representação de um botão baseado 
 * em interfaces GUI.
 *
 * Author Marcelo Costa Collyer (marcelocollyer@gmail.com) 
 *
 **************************************************************/
#ifndef __CSBUTTON_H__
#define __CSBUTTON_H__

#include "SDL.h"
#include "SDL_ttf.h"
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
			TTF_Font *font;
			SDL_Color color;

		public:			
			CSButton(char *, int, int);
			~CSButton(void);
			
			STATE_ENUM state;
			char* downImagePath;
			char* lightImagePath;
			char* defaultImagePath;

			SDL_Surface *surface;
			void FireChangeImageEvent(SDL_Event*);
			void SetLabel(char*);
			void SetFont(TTF_Font *);
			void SetColor(SDL_Color);
			void CSButton::SetLabel(char *label, TTF_Font *font, SDL_Color color);
	};
}

#endif //__CSBUTTON_H__