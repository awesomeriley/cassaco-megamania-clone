/*************************************************************
 * Classe que representa a classe base para todas as naves 
 * inimigas, toda nave inimiga deve herdar desta classe e 
 * implementar a função Update(void) que indica como cada 
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
	 * Construtor ~padrão que cria um novo inimigo, informando 
	 * a animação do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	Enemy::Enemy(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException) : Ship(file, frameWidth, frameHeight)
	{
		width = WIDTH_SCREEN;
		height = HEIGHT_SCREEN;
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo inimigo
	 *
	 *************************************************************/
	Enemy::~Enemy(void)
	{
	}
}
