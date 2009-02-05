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
	 * Construtor ~padrão que cria um novo inimigo, informando 
	 * a animação do mesmo, a largura e altura de cada frame
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
	 * Função responsavel por realizar a animação da morte do
	 * inimigo
	 *
	 *************************************************************/
	void Enemy::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Função responsavel por realizar a ação de atirar
	 *
	 *************************************************************/
	void Enemy::Shoot(void)
	{
	}

	/*************************************************************
	 * Função responsavel por setar a animação de morte do
	 * inimigo
	 *
	 *************************************************************/
	void Enemy::SetDieAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	{
	}

	/*************************************************************
	 * Função que seta o estado atual do inimigo
	 *
	 *************************************************************/
	void Enemy::SetState(EnemyState state)
	{
	}

	/*************************************************************
	 * Função responsavel por retornar o estado atual do inimigo
	 *
	 *************************************************************/
	void Enemy::GetState(EnemyState &state)
	{		
	}
}
