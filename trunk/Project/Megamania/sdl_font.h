/**********************************************************************
 * Classe responsavel por manipular os dados relacionados com 
 * os sons do jogo , bem como a musica.
 * Esta classe possui operações básicas com tocar um som, uma musica
 * realizar operações de FADE, aumentar e diminuir o volume do som
 * ou música e pausar.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 *********************************************************************/
#ifndef __SDL_TTF_H__
#define __SDL_TTF_H__

#include "SDL.h"
#include "SDL_ttf.h"
#include "font_exception.h"

namespace Megamania
{
	class SDL_Font
	{
		private:
			TTF_Font *font;
			SDL_Color color;
		public:
			SDL_Font(const char *, int)throw(SDLFontException);
			~SDL_Font(void);
			SDL_Surface * RenderTextSolid(const char *);
			void SetColor(Uint8, Uint8, Uint8);
			void GetColor(Uint8&, Uint8&, Uint8&);
			const int GetHeight(void)const;
	};
}

#endif //__SDL_TTF_H__