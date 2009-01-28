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
			int frameWidth;
			/** variavel que indica a altura de cada frame do objeto Sprite*/
			int frameHeight;
			/** variavel que indica a quantidade de frames total do objeto Sprite*/
			int nFrames;
			/** cursor que indica o frame corrente*/
			int currentIndex;
			/** ponteiro para a imagem do objeto Sprite*/
			SDL_Surface *image;
			/** vetor responsavel por gerenciar cada frame do objeto*/
			std::vector<SDL_Rect> frames;
		public:
			Sprite(const char *);
			~Sprite(void);
			void NextFrame(void);
			void PrevFrame();
			void SetX(void);
			void SetY(void);
			void SetPosition(int x, int y);
			void Move(int dx, int dy);
			int GetWidthFrame(void);
			int GetHeightFrame(void);
			int GetFrameNumbers(void);
			bool CollidesWith(Sprite&);
			void Draw(SDL_Surface *surface);
	};
}

#endif //__SDL_SPRITE_H__