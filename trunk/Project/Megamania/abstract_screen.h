/******************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que deverão
 * ser implementadas por todas as sub-classes:
 *
 *
 *
 *
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 * 
 *****************************************************************/
#ifndef __ABSTRACT_SCREEN_H__
#define __ABSTRACT_SCREEN_H__

#include "SDL.h"
#include "video_exception.h"
#include <vector>

namespace Megamania
{
	class AbstractScreen
	{
		protected:
			/** referencia para a Surface principal do JOGO*/
			SDL_Surface *screen;
			/** array que contém todas as surfaces utilizadas pela tela*/
			std::vector<SDL_Surface *> surfaces;
		public:
			AbstractScreen(SDL_Surface *)throw(SDLVideoException);
			virtual ~AbstractScreen(void) = 0;
			virtual bool OnInit(void) = 0;
			virtual void OnExecute(void) = 0;
			virtual void OnEvent(SDL_Event *) = 0;
            virtual void OnDraw(void) = 0;
			virtual void OnClear(void) = 0;
	};
}

#endif //__ABSTRACT_SCREEN_H__