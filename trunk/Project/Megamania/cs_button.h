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
#include "sdl_font.h"

namespace Megamania
{
	class CSButton 
	{
		enum STATE_ENUM {DEFAULT, DOWN, HIGH_LIGHT};
		
		private:			
			int x; 
			int y;
			char *text;
			SDL_Font *font;			
			STATE_ENUM state;
			char *downImagePath;
			char *lightImagePath;
			char *defaultImagePath;
			SDL_Surface *surface;
			void ChangeState(char *, STATE_ENUM);
		public:			
			CSButton(char *, int, int);
			~CSButton(void);									
			void FireChangeImageEvent(SDL_Event*);
			void SetText(const char *);
			void SetFont(SDL_Font *);			
			SDL_Surface * GetSurface(void);
			void Draw(SDL_Surface *);
	};
}

#endif //__CSBUTTON_H__