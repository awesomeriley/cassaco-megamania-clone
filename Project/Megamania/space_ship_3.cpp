/*************************************************************
 * Classe que representa a nave inimiga da fase um, esta nave
 * somente se movimenta de um lado para outro.
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#include "space_ship_3.h"

namespace Megamania 
{
	/*************************************************************
	 * Construtor padrão responsavel por criar o objeto nave,
	 * aqui são definidos o Sprite da nave e sua largura e altura
	 * respectivamente, esses dados se encontram definidos no 
	 * arquivo game_config.h
	 *
	 *************************************************************/
	SpaceShip3::SpaceShip3(void)throw(SpriteException) : 
	Enemy(PATH_SPACE_SHIP_3, SPACE_SHIP_3_WIDTH, SPACE_SHIP_3_HEIGHT)
	{
		offsetX = SPACE_SHIP_3_OFFSET_X;
		offsetY = SPACE_SHIP_3_OFFSET_Y;
		direction = Direction::DOWN;
		dx = dy = 0;
	}
	
	/*************************************************************
	 * Função responsavel por atualizar a posição da nave em 
	 * relação a tela
	 *
	 *************************************************************/
	void SpaceShip3::Update(void) 
	{
		int hLimitInf = GetHeightFrame() + (GetHeightFrame() >> 1);
		int hLimitSup = height >> 1;		
		if(GetX() + offsetX < width) {
			Move(offsetX, 0);
		} else {
			SetX(-GetWidthFrame());
		}
		dx += offsetX;
		if(dx >= LEVEL_3_DISPLACEMENT_X) {
			dx = 0;
			if(direction == Direction::DOWN) {
				if(GetY() + offsetY < clipRect.h) {												
					Move(0, offsetY);							    			
				} else {		
					direction = Direction::UP;
				}
			} else {		
				if(GetY() - offsetY > clipRect.y) {								
					Move(0, -offsetY);							    			
				} else {									
					direction = Direction::DOWN;
				}
			}
		}
	}

	/*************************************************************
	 * Função que retorna a pontuação de cada nave, ou seja o
	 * valor que cada nave acresce ao Score
	 *
	 *************************************************************/
	int SpaceShip3::GetPointValue(void) 
	{
		return SPACE_SHIP_3_SCORE;
	}
}
