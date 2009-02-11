/****************************************************************
 * Classe que representa um Sprite, um Sprite nada mais é que
 * um elemento que pode ser renderizado e exibir diferentes 
 * frames de uma imagem informada, realizando assim uma animação
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
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
			Uint16 frameWidth;
			/** variavel que indica a altura de cada frame do objeto Sprite*/
			Uint16 frameHeight;
			/** variavel que indica a quantidade de frames total do objeto Sprite*/
			Uint16 nFrames;
			/** cursor que indica o frame corrente*/
			Uint16 cursor;
			/** ponteiro para a imagem do objeto Sprite*/
			SDL_Surface *image;						
			/** vetor responsavel por gerenciar cada frame do objeto*/
			std::vector<SDL_Rect *> frames;
			/** flag responsavel por indicar se o Sprite esta ou não visivel*/
			bool visible;
		private:
            void CreateFrames(void);
		public:
			enum Mirror { MIRROR_NONE, MIRROR_LEFT_RIGTH, MIRROR_UP_DOWN };
			Sprite(const char *, Uint16, Uint16)throw(SpriteException);
			~Sprite(void);
			void NextFrame(void);
			void PrevFrame(void);
			int GetCurrentFrame(void);
			void SetFrame(int);
			void SetX(int);
			void SetY(int);
			const int GetX(void)const;
			const int GetY(void)const;
			void SetPosition(int, int);
			void GetPosition(int &, int &);
			void Move(int, int);
			const int GetWidthFrame(void)const;
			const int GetHeightFrame(void)const;
			const int GetFrameNumbers(void)const;
			bool CollidesWith(Sprite&);
			bool IsVisible(void);
			void SetVisible(bool visible);
			virtual void Draw(SDL_Surface *);
	};
}

#endif //__SDL_SPRITE_H__