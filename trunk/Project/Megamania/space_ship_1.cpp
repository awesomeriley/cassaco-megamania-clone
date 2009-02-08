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
	 * Construtor padrão responsavel por criar o objeto nave,
	 * aqui são definidos o Sprite da nave e sua largura e altura
	 * respectivamente, esses dados se encontram definidos no 
	 * arquivo game_config.h
	 *
	 *************************************************************/
	SpaceShip1::SpaceShip1(void)throw(SpriteException) : 
	Enemy(PATH_SPACE_SHIP_1, SPACE_SHIP_1_WIDTH, SPACE_SHIP_1_HEIGHT)
	{
		offset = SPACE_SHIP_1_OFFSET;
	}
	
	/*************************************************************
	 * Função responsavel por atualizar a posição da nave em 
	 * relação a tela
	 *
	 *************************************************************/
	void SpaceShip1::Update(void) 
	{
		if(GetX() + offset < width) {
			Move(offset, 0);
		} else {
			SetX(-GetWidthFrame());
		}
	}
}
