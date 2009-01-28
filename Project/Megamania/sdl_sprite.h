/**
 * Classe que representa um Sprite, um Sprite nada mais é que
 * um elemento que pode ser renderizado e exibir diferentes 
 * frames de uma imagem informada, realizando assim uma animação
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __SDL_SPRITE_H__
#define __SDL_SPRITE_H__

#include "SDL.h"
#include "sprite_exception.h"
#include <vector>

namespace Megamania
{
	class Sprite 
	{
		private:
			/** variavel que indica a posição do Sprite na coordenada X*/
			int x;
			/** variavel que indica a posição do Sprite na coordenada Y*/
			int y;
			/** variavel que indica a largura de cada frame do objeto Sprite*/
			Uint32 frameWidth;
			/** variavel que indica a altura de cada frame do objeto Sprite*/
			Uint32 frameHeight;
			/** variavel que indica a quantidade de frames total do objeto Sprite*/
			Uint32 nFrames;
			/** cursor que indica o frame corrente*/
			Uint32 cursor;
			/** ponteiro para a imagem do objeto Sprite*/
			SDL_Surface *image;
			/** vetor responsavel por gerenciar cada frame do objeto*/
			std::vector<struct SDL_Rect> frames;			
		private:
            void CreateFrames(void);
		public:
			Sprite(const char *, Uint32, Uint32)throw(SpriteException);
			~Sprite(void);
			void NextFrame(void);
			void PrevFrame(void);
			void SetX(int x);
			void SetY(int y);
			const int GetX(void)const;
			const int GetY(void)const;
			void SetPosition(int x, int y);
			void Move(int dx, int dy);
			const int GetWidthFrame(void)const;
			const int GetHeightFrame(void)const;
			const int GetFrameNumbers(void)const;
			bool CollidesWith(Sprite&);
			void Draw(SDL_Surface *surface);
	};
}

#endif //__SDL_SPRITE_H__