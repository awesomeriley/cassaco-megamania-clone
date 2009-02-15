/*************************************************************
 * Classe que representa a nave inimiga da fase dois
 *
 * Author: Marcelo Collyre
 * Email : marcelocollyer@gmail.com  
 *
 *************************************************************/
#include "space_ship_2.h"

namespace Megamania 
{
	/*************************************************************
	 * Construtor padr�o responsavel por criar o objeto nave,
	 * aqui s�o definidos o Sprite da nave e sua largura e altura
	 * respectivamente, esses dados se encontram definidos no 
	 * arquivo game_config.h
	 *
	 *************************************************************/
	SpaceShip2::SpaceShip2(void)throw(SpriteException) : 
	Enemy(PATH_SPACE_SHIP_2, SPACE_SHIP_2_WIDTH, SPACE_SHIP_2_HEIGHT)
	{
		offset = SPACE_SHIP_2_OFFSET;
	}
	
	/*************************************************************
	 * Fun��o responsavel por atualizar a posi��o da nave em 
	 * rela��o a tela
	 *
	 *************************************************************/
	void SpaceShip2::Update(void) 
	{
		if(GetX() + offset < width) {
			Move(offset, 0);
		} else {
			SetX(-GetWidthFrame());
		}
	}

	/*************************************************************
	 * Fun��o que retorna a pontua��o de cada nave, ou seja o
	 * valor que cada nave acresce ao Score
	 *
	 *************************************************************/
	int SpaceShip2::GetPointValue(void) 
	{
		return SPACE_SHIP_2_SCORE;	
	}
}
