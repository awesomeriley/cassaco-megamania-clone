/*************************************************************
 * Classe que representa a classe base para todas as naves 
 * inimigas, toda nave inimiga deve herdar desta classe e 
 * implementar a função Update(void) que indica como cada 
 * nave deve se mover
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "sprite_exception.h"
#include "ship.h"
#include "game_config.h"
#include "bullet.h"

namespace Megamania
{
	class Enemy : public Ship
	{   
		protected:
			/**
			 * variavel que indica a largura total da tela, utilizada para o
			 * movimento da nave
			 */
			Uint16 width;
			/** 
			 * variavel que indica a altura total da tela, utilizada para o 
			 * movimento da nave
			 */
			Uint16 height;
			/** variavel que indica o deslocamento no eixo X*/
			int dx;
			/** variavel que indica o deslocamento no eixo Y*/
			int dy;
			/**
			 * Retangulo auxiliar que pode ser utilizado por alguma sub-classe indicando
			 * a posição maxima e minima de movimentação da mesma, por exemplo:
			 *  
			 * clipRect.x = 10;
			 * clipRect.y = 10;
			 * clipRect.w = 300;
			 * clipRect.h = 300;
			 *
			 * A atribuição acima, indica que a nave tem como posição minima no eixo X e Y
			 * 10 pixels e como posição maxima para o eixo X e Y 300 pixels - a altura da
			 * nave
			 */
			SDL_Rect clipRect;
		public:
			Enemy(const char *, Uint16, Uint16)throw(SpriteException);
			void Draw(SDL_Surface *);
			virtual void Update(void) = 0;
			virtual int GetPointValue(void) = 0;
			SDL_Rect & GetClipPosition();
	};
}

#endif  //__ENEMY_H__