/*****************************************************************
 * Classe que representa a barra de status do jogo, aqui são
 * visualizados o timer do jogo, as vidas e os respectivos 
 * pontos adquiridos
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
#ifndef __HUD_H__
#define __HUD_H__

#include "SDL.h"
#include "game_config.h"
#include "sdl_font.h"
#include "sdl_effect.h"

namespace Megamania
{
	class HUD 
	{
		private:
			/** retangulo usado para posicionar o componente HUD*/
			SDL_Rect rect;
			/** retangulo que indica a area que poderá ser pintada*/
			SDL_Rect clipRect;
			/** ponteiro para a unica instancia da classe*/
			static HUD *singleton;
			/** Objeto que indica onde o HUD será pintado*/
			SDL_Surface *surface;
			/** Objeto responsavel por pintar o Score*/
			SDL_Font *font;
			/** Objeto que representa o painel do HUD*/
			SDL_Surface *panel;
			/** 
			 * Objeto que representa o energy Bar usado para incrementar
			 * o painel
			 */
			SDL_Surface *energyBar;
			/** 
			 * Objeto que representa o energy Bar usado para decrementar
			 * o painel
			 */
			SDL_Surface *energyBar2;
			/** Objeto que representa uma vida*/
			SDL_Surface *shipIcon;
			/** variavel que indica a pontuação do usuario*/
			int point;
			/** variavel que indica pontos a ser aplicado quando o HUD for decrementado*/
			int pointByDecrement;
			/** variavel que indica a pontuação minima*/
			int minP;
			/** variavel que indica a pontuação maxima*/
			int maxP;
			/** Objeto que representa o efeito a ser tocado quando o HUD estiver enchendo*/
			Effect *effect;
			/** variavel que indica a quantidade de vidas*/
			int lifes;
			/** variavel que indica a posição atual a ser decrementada no HUD*/
			int cursor;
			/** variavel que indica o delay usado para desenhar a barra enchendo*/
			const static int delay = HUD_DELAY;
			HUD(void);
		public:
			static HUD * GetInstance(void)
			{
				if(singleton == NULL) {
					singleton = new HUD();
				}
				return singleton;
			}
			SDL_Rect & GetRect(void);
			void SetPoint(int);
			void IncrementPoint(int);
			void SetLife(int);
			void IncrementLife(void);
			void DecrementLife(void);
			void Full(void);
			void Empty(void);
			void UpdateLife(void);
			void UpdateScore(void);
			bool Draw(void);
	};
}

#endif //__HUD_H__