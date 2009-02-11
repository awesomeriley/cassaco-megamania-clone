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
	 *
	 *************************************************************/
	Bullet::Bullet(void)throw(SpriteException) :
	GameObject(PATH_BULLET, BULLET_WIDTH, BULLET_HEIGHT)
	{
	}

	/*************************************************************
	 *
	 *************************************************************/
	Bullet::~Bullet(void) 
	{
	}

	/*************************************************************
	 *
	 *************************************************************/
	void Bullet::Update(Direction direction) 
	{
		if(direction == Direction::UP) {
			if(GetY() - BULLET_OFFSET > 0) {
				Move(0, -BULLET_OFFSET);
			} else {
				SetVisible(false);
			}			
		} else {
			if(GetY() + BULLET_OFFSET < HEIGHT_SCREEN) {
				Move(0, BULLET_OFFSET);
			} else {
				SetVisible(false);
			}			
		}
	}
}