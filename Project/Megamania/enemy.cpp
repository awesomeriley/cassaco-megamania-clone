/*************************************************************
 * Classe que representa a classe base para todas as naves 
 * inimigas, toda nave inimiga deve herdar desta classe e 
 * implementar a fun��o Update(void) que indica como cada 
 * nave deve se mover
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com  
 *
 *************************************************************/
#include "enemy.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor ~padr�o que cria um novo inimigo, informando 
	 * a anima��o do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	Enemy::Enemy(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException) : Ship(file, frameWidth, frameHeight)
	{
		width = WIDTH_SCREEN;
		height = HEIGHT_SCREEN;
	}

	/*************************************************************
	 * Fun��o responsavel por desenhar na tela todos os objetos
	 *
	 *************************************************************/
	void Enemy::Draw(SDL_Surface *surface)
	{
		if(bullet->IsVisible()) {			
			bullet->Update(Megamania::Bullet::Direction::DOWN);
			bullet->Draw(surface);
		}
		GameObject::Draw(surface);
	}

	/*******************************************************************************
	 * Fun��o que retorna o retangulo que indica a area de movimenta��o da nave
	 * indicando a posi��o maxima e minima de movimenta��o da mesma, por exemplo:
	 *  
	 * clipRect.x = 10;
	 * clipRect.y = 10;
	 * clipRect.w = 300;
	 * clipRect.h = 300;
	 *
	 * A atribui��o acima, indica que a nave tem como posi��o minima no eixo X e Y
	 * 10 pixels e como posi��o maxima para o eixo X e Y 300 pixels - a altura da
	 * nave
	 ********************************************************************************/
	SDL_Rect & Enemy::GetClipPosition()
	{
		return this->clipRect;
	}
}
