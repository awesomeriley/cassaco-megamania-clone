/*************************************************************
 * Classe que representa a nave inimiga da fase um, esta nave
 * somente se movimenta de um lado para outro.
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#include "space_ship_1.h"

namespace Megamania 
{
	/*************************************************************
	 * Construtor padr�o responsavel por criar o objeto nave,
	 * aqui s�o definidos o Sprite da nave e sua largura e altura
	 * respectivamente, esses dados se encontram definidos no 
	 * arquivo game_config.h
	 *
	 *************************************************************/
	SpaceShip1::SpaceShip1(void)throw(SpriteException) : 
	Enemy(PATH_SPACE_SHIP_1, SPACE_SHIP_1_WIDTH, SPACE_SHIP_1_HEIGHT)
	{
		offsetX = SPACE_SHIP_1_OFFSET_X;
	}
	
	/*************************************************************
	 * Fun��o responsavel por atualizar a posi��o da nave em 
	 * rela��o a tela
	 *
	 *************************************************************/
	void SpaceShip1::Update(void) 
	{
		if(GetX() + offsetX < width) {
			Move(offsetX, 0);
		} else {
			SetX(-GetWidthFrame());
		}
	}

	/*************************************************************
	 * Fun��o que retorna a pontua��o de cada nave, ou seja o
	 * valor que cada nave acresce ao Score
	 *
	 *************************************************************/
	int SpaceShip1::GetPointValue(void) 
	{
		return SPACE_SHIP_1_SCORE;
	}
}
