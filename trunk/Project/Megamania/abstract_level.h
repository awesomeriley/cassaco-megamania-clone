/***************************************************************
 * Classe que representa a classe base para todas as fases 
 * do jogo, toda fase dever� herdar diretamente desta classe
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#ifndef __ABSTRACT_LEVEL_H__
#define __ABSTRACT_LEVEL_H__

#include "ship.h"
#include "enemy.h"
#include "hud.h"
#include "video_exception.h"
#include "game_config.h"
#include "abstract_screen.h"
#include <vector>

namespace Megamania
{
	class AbstractLevel : public AbstractScreen
	{
		protected:
			/** vetor que cont�m os inimigos a serem exibidos*/
			std::vector<Enemy *> enemies;
			/** objeto que representa a nave principal do jogo*/
			Ship *megamania;
			/** flag que indica se o jogo j� esta completo ou n�o*/
			bool levelComplete;
			/** variavel que indica a quantidade de naves por level*/
			Uint16 shipCount;
			/** referencia para o Objeto HUD*/
			HUD *hud;
			/** variavel que indica o tempo da ultima execu��o*/
			int lastTimer;
			/** variavel que indica o tempo atual da execu��o*/
			int currentTimer;
			/** variavel responsavel por acumular o tempo de execu��o*/
			int timerAcum;
			/** constante que indica o delay utilizado para a pintura*/
			const static int DELAY = HUD_DRAW_DELAY;
			/* variavel que guarda o codigo encapsulado no SDL_event 
			 * para indicar qual o numero da fase
			 */
			int levelFinishEvent;
			/** finaliza o level */
			void FinishLevel(void);
		public:
			AbstractLevel(SDL_Surface *)throw(SDLVideoException);
			~AbstractLevel(void);
			void SetMegamania(Ship *);
			void SetShipCount(Uint16);
			virtual void Init(void);
			virtual void Execute(void);
			virtual void Event(SDL_Event *);
            virtual void Draw(void);
			virtual void Clear(void);
	};
}

#endif //__ABSTRACT_LEVEL_H__