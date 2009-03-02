/*************************************************************
 * Classe que representa a bala do jogo, uma bala pode esta
 * associada tanto a nave principal, como a uma nave inimiga
 *
 * Author : Marcelo Collyer
 * Email : marcelocollyer@gmail.com
 *
 *************************************************************/
#include "bullet.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor padr�o que cria um novo objeto Bullet
	 * 
	 *************************************************************/
	Bullet::Bullet(void)throw(SpriteException) :
	GameObject(PATH_BULLET, BULLET_WIDTH, BULLET_HEIGHT)
	{
	}

	/*************************************************************
	 * Fun��o que atualiza a posi��o atual da bala, esta fun��o
	 * recebe como parametro um valor indicando se a bala dever�
	 * subir ou dever� descer
	 *
	 *************************************************************/
	void Bullet::Update(Direction direction) 
	{
		if(direction == Direction::UP) {
			if(GetY() - BULLET_OFFSET > - GetHeightFrame()) {
				Move(0, -BULLET_OFFSET);
			} else {
				SetVisible(false);
			}			
		} else {
			if(GetY() + BULLET_OFFSET < HEIGHT_SCREEN + GetHeightFrame()) {
				Move(0, BULLET_OFFSET);
			} else {
				SetVisible(false);
			}			
		}
	}
}