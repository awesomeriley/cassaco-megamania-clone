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
	 * Construtor padrão responsavel por criar o objeto nave,
	 * aqui são definidos o Sprite da nave e sua largura e altura
	 * respectivamente, esses dados se encontram definidos no 
	 * arquivo game_config.h
	 *
	 *************************************************************/
	SpaceShip2::SpaceShip2(void)throw(SpriteException) : 
	Enemy(PATH_SPACE_SHIP_2, SPACE_SHIP_2_WIDTH, SPACE_SHIP_2_HEIGHT)
	{
		offsetX = SPACE_SHIP_2_OFFSET_X;
		offsetY = SPACE_SHIP_2_OFFSET_Y;
		direction = Direction::RIGHT;
		dx = dy = 0;
		isDown = false;
	}
	
	/*************************************************************
	 * Função responsavel por atualizar a posição da nave em 
	 * relação a tela
	 *
	 *************************************************************/
	void SpaceShip2::Update(void) 
	{
		static int count = 0;
		if(isDown) {
			if(direction == Direction::RIGHT) {
				Move(-offsetY, offsetY);												
			} else {
				Move(offsetY, offsetY);											
			}			
			++count;
			if(count == 2) {
				count = 0;
				isDown = false;
			}	
			isDown = false;
		} else if(direction == Direction::RIGHT) {
			if(dx + offsetX < LEVEL_2_DISPLACEMENT_X) {
				if(GetX() + offsetX < width) {				
					Move(offsetX, 0);
				} else {
					SetX(-GetWidthFrame());
				}				
				dx += offsetX;
			} else {				
				direction = Direction::LEFT;
				isDown = true;
			}
		} else if(direction == Direction::LEFT) {
			if(dx - offsetX > 0) {
				if(GetX() - offsetX > 0) {				
					Move(-offsetX, 0);
				} else {
					SetX(width + GetWidthFrame());
				}				
				dx -= offsetX;				
			} else {		
				direction = Direction::RIGHT;
				isDown = true;
			} 
		}
		if(GetY() > height) {
			SetY(-GetHeightFrame());
		}
	}

	/*************************************************************
	 * Função que retorna a pontuação de cada nave, ou seja o
	 * valor que cada nave acresce ao Score
	 *
	 *************************************************************/
	int SpaceShip2::GetPointValue(void) 
	{
		return SPACE_SHIP_2_SCORE;	
	}
}
