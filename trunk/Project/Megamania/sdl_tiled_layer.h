/***************************************************************************
 * Classe que representa uma grade de celulas onde podemos setar os tiles
 * que irão compor o background do JOGO, com esta classe podemos enormes 
 * telas virtuais sem que para isso tenhamos que utilizar grandes imagens
 * esta tecnica é muito utilizada para o desenvolvimento de jogos 2D e para
 * a realização do Scrolling da tela
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************************/
#ifndef __SDL_TILED_LAYER_H__
#define __SDL_TILED_LAYER_H__

#include "SDL.h"
#include "sprite_exception.h"
#include "sdl_sprite.h"

namespace Megamania
{
	class TiledLayer 
	{
		private:
			/** Objeto que representa os tiles que compõem o background do JOGO*/
			Sprite *tiles;
			/** variavel que indica a largura de cada tile*/
			Uint16 tileWidth;
			/** variavel que indica a altura de cada tile*/
			Uint16 tileHeight;
			/** variavel que indica a quantidade total de colunas*/
			Uint32 columns;
			/** variavel que indica a quantidade total de linhas*/
			Uint32 rows;
			/** variavel que indica a quantidade de tiles*/
			Uint32 tilesLength;
			/** array que contém a quantidade total de tiles a ser desenhada*/	
			int *map;
			/** constante que indica a ausencia de um tile na celula*/
			const static int EMPTY_TILE_INDEX = 0xffffffff;
			/** 
			 * constante que indica a quantidade default da celula caso seja informado
			 * um parametro invalido
			 */
			const static int DEFAULT_SIZE_CELLS = 1;
		public:
			TiledLayer(Uint32, Uint32, const char *, Uint16, Uint16)throw(SpriteException);
			TiledLayer(const char *)throw(SpriteException);
			~TiledLayer(void);
			Uint32 GetColumns(void);
			Uint32 GetRows(void);
			Uint16 GetCellWidth(void);
			Uint16 GetCellHeight(void);
			void SetCell(Uint32, Uint32, Uint32);
			void FillCells(int *, int lenght);
			Uint32 GetCell(Uint32, Uint32);
			void Draw(SDL_Surface *);
	};
}

#endif //__SDL_TILED_LAYER_H__