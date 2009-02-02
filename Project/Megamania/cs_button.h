/***************************************************************
 * Arquivo que define a interface publica para a classe 
 * CSButton que � a representa��o de um bot�o baseado 
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

		/*
		 * Enumerations que cont�m constantes utilizadas pelo pintura do 
		 * bot�o
		 */

		enum STATE_ENUM { DEFAULT, DOWN, HIGH_LIGHT };
		enum V_ALIGNMENT { TOP, VCENTER, BOTTOM };
		enum H_ALIGNMENT { LEFT, HCENTER, RIGHT };

		private:		
			/** variavel que indica a posi��o do bot�o no eixo X*/
			int x; 
			/** variavel que indica a posi��o do bot�o no eixo Y*/
			int y;
			/** variavel que indica a posi��o do texto do bot�o no eixo X*/
			int textX;
			/** variavel que indica a posi��o do texto do bot�o no eixo Y*/
			int textY;
			/** indica o texto a ser aplicado sobre o bot�o*/
			char *text;
			/** indica  a fonte a ser aplicada sobre o texto*/
			SDL_Font *font;			
			/** flag responsavel por indicar o estado do bot�o*/
			STATE_ENUM state;
			/** surface responsavel por pintar o bot�o*/
			SDL_Surface *surface;
			void ChangeState(char *, STATE_ENUM);
		public:			
			CSButton(char *, int, int);
			~CSButton(void);									
			void FireChangeImageEvent(SDL_Event *);
			void SetText(const char *);
			void SetFont(SDL_Font *);			
			SDL_Surface * GetSurface(void);
			void Draw(SDL_Surface *);
			void SetAlign(V_ALIGNMENT, H_ALIGNMENT);
	};
}

#endif //__CSBUTTON_H__