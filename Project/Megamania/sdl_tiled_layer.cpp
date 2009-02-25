/***************************************************************************
 * Classe que representa uma grade de celulas onde podemos setar os tiles
 * que ir�o compor o background do JOGO, com esta classe podemos enormes 
 * telas virtuais sem que para isso tenhamos que utilizar grandes imagens
 * esta tecnica � muito utilizada para o desenvolvimento de jogos 2D e para
 * a realiza��o do Scrolling da tela
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************************/
#include "sdl_tiled_layer.h"

namespace Megamania
{

	/***************************************************************************
	 * Construtor que cria um novo objeto TiledLayer apartir dos dados 
	 * informados, segue abaixo uma explica��o sobre cada parametro esperado:
	 *
	 * - columns -> indica a quantidade de colunas que o objeto TiledLayer 
	 * cont�m, as colunas s�o preenchidas da esquerda para a direita da tela
	 * - rows -> indica a quantidade de linhas que o objeto TiledLayer cont�m
	 * as linhas s�o preenchidas do canto superior ao canto inferior da tela
	 * - file -> indica o path para a imagem que comp�e o objeto TiledLayer
	 * - tileWidth -> indica a largura de cada tile
	 * - tileHeight -> indica a altura de cada tile
	 * 
	 * Caso seja passado como parametro um valor invalido ser� disparada uma 
	 * SpriteException, j� que para a tile ser composta a mesma utiliza um objeto
	 * Sprite, por valores invalidos, significa uma largura ou altura que n�o 
	 * comp�em um Sprite com imagens exatas.
	 *
	 *
	 ***************************************************************************/
	TiledLayer::TiledLayer(Uint32 columns, Uint32 rows, const char *file, Uint16 tileWidth, Uint16 tileHeight)
	throw(SpriteException)
	{
		tiles = new Sprite(file, tileWidth, tileHeight);
		this->tileWidth = tileWidth;
		this->tileHeight = tileHeight;
		if(columns <= 0) {
			columns = DEFAULT_SIZE_CELLS;
		}
		if(rows <= 0) {
			rows = DEFAULT_SIZE_CELLS;
		}
		this->columns = columns;
		this->rows = rows;
		tilesLength = columns * rows;
		int len = sizeof(int) * tilesLength;
		map = reinterpret_cast<int *>(SDL_malloc(len));
		memset(map, EMPTY_TILE_INDEX, len);    //preenche todas as celulas com -1
	}

	/***************************************************************************
	 * Destruidor responsavel por desalocar todos os recursos alocados pelo
	 * objeto TiledLayer
	 *
	 ***************************************************************************/
	TiledLayer::~TiledLayer(void)
	{
		delete tiles;
		SDL_free(map);
	}

	/***************************************************************************
	 * Fun��o que retorna o numero indicando a quantidade de colunas do 
	 * objeto TiledLayer
	 *
	 ***************************************************************************/
	Uint32 TiledLayer::GetColumns(void)
	{
		return this->columns;
	}
	
	/***************************************************************************
	 * Fun��o que retorna o numero indicando a quantidade de linhas do 
	 * objeto TiledLayer
	 *
	 ***************************************************************************/
	Uint32 TiledLayer::GetRows(void)
	{
		return this->rows;
	}
	
	/***************************************************************************
	 * Fun��o que retorna o numero indicando a largura de cada tile
	 *
	 ***************************************************************************/
	Uint16 TiledLayer::GetCellWidth(void)
	{
		return this->tileWidth;		
	}
	
	/***************************************************************************
	 * Fun��o que retorna o numero indicando a altura de cada tile
	 *
	 ***************************************************************************/
	Uint16 TiledLayer::GetCellHeight(void)
	{
		return this->tileHeight;
	}

	/***************************************************************************
	 * Fun��o que associa um indice do tile a uma posi��o no map que cont�m 
	 * os tiles a serem desenhados, caso seja passado como parametro um indice
	 * invalido ocorrer� um erro
	 *
	 ***************************************************************************/
	void TiledLayer::SetCell(Uint32 column, Uint32 row, Uint32 tileIndex)
	{
		this->map[column * row] = tileIndex;
	}
	
	/***************************************************************************
	 * Fun��o que preenche a estrutura que cont�m os dados a serem desenhados
	 * com os valores da estrutura informada como parametro, caso o tamanho do 
	 * array informado n�o seja igual a quantidade de linhas x colunas informadas
	 * ou o array informado seja NULL nada ocorrer� , o que poder� ocasionar 
	 * um erro posterior
	 *
	 ***************************************************************************/
	void TiledLayer::FillCells(int *_map, int lenght)
	{
		if((lenght == tilesLength)&&(_map != NULL)) {
			for(int i = 0; i < lenght; ++i) {
				map[i] = _map[i];
			}
		}
	}

	/***************************************************************************
	 * Fun��o que retorna o indice do tile associado com a posi��o informada
	 * caso seja passado como parametro um indice invalido ocorrer� um erro
	 *
	 ***************************************************************************/
	Uint32 TiledLayer::GetCell(Uint32 column, Uint32 row)
	{
		return map[column * row];
	}

	/***************************************************************************
	 * Fun��o responsavel por desenhar todos os tiles na surface fornecida
	 * os tiles a serem desenhados poder�o ser pintados fora da area visivel
	 * da surface
	 *
	 ***************************************************************************/
	void TiledLayer::Draw(SDL_Surface *surface)
	{
		int currentColumn = 0xffffffff;    
		if(surface != NULL) {
			for(int i = 0; i < columns; ++i) {
				currentColumn = i % columns;
				for(int j = 0; j < rows; ++j) {
					tiles->SetFrame(map[j * rows + i]);
					tiles->SetPosition(currentColumn * tileHeight, (j % rows) * tileWidth);
					tiles->Draw(surface);
				}
			}
		}
	}
}
