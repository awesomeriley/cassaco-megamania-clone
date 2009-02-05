/*************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
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
	throw(SpriteException) : Sprite(file, frameWidth, frameHeight)
	{
		state = EnemyState::STOPPED;
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo inimigo
	 *
	 *************************************************************/
	Enemy::~Enemy(void)
	{
		delete dieing;
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a anima��o da morte do
	 * inimigo
	 *
	 *************************************************************/
	void Enemy::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a a��o de atirar
	 *
	 *************************************************************/
	void Enemy::Shoot(void)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por setar a anima��o de morte do
	 * inimigo
	 *
	 *************************************************************/
	void Enemy::SetDieAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	{
	}

	/*************************************************************
	 * Fun��o que seta o estado atual do inimigo
	 *
	 *************************************************************/
	void Enemy::SetState(EnemyState state)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por retornar o estado atual do inimigo
	 *
	 *************************************************************/
	void Enemy::GetState(EnemyState &state)
	{		
	}
}
