/********************************************************************
 * Classe que representa a classe base para todas as classes do
 * jogo, esta classe apresenta os seguintes estados que deverão
 * ser implementadas por todas as sub-classes:
 *
 * -Init -> Função responsavel por iniciar o estado da tela
 * -Execute -> Função responsavel por exibir a tela 
 * -Event -> Função de callback que será chamada pelo gerenciador
 * de eventos quando ocorrer algum evento, repassando assim para a 
 * tela o evento que ocorreu
 * -Draw -> Função responsavel por pintar ou repintar a tela
 * -Clear -> Função que deve ser chamada quando a tela não for
 * mais necessaria, realizando assim uma limpeza antes de sair
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 * 
 *******************************************************************/
#ifndef __ABSTRACT_SCREEN_H__
#define __ABSTRACT_SCREEN_H__

#include "SDL.h"
#include "video_exception.h"

namespace Megamania
{
	class AbstractScreen
	{
		protected:
			/** referencia para a Surface principal do JOGO*/
			SDL_Surface *screen;
		public:
			AbstractScreen(SDL_Surface *)throw(SDLVideoException);
			virtual ~AbstractScreen(void);
			void SetTitle(const char *);
			void SetIcon(const char *);
			virtual void Init(void) = 0;
			virtual void Execute(void) = 0;
			virtual void Event(SDL_Event *) = 0;
            virtual void Draw(void) = 0;
			virtual void Clear(void) = 0;
	};
}

#endif //__ABSTRACT_SCREEN_H__