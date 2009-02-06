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
#include "game_object.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor ~padr�o que cria um novo ator, informando 
	 * a anima��o do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	GameObject::GameObject(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException) : Sprite(file, frameWidth, frameHeight)
	{
		state = GameObjectState::STOPPED;
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo ator
	 *
	 *************************************************************/
	GameObject::~GameObject(void)
	{
		delete dying;
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a anima��o da morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a a��o de atirar
	 *
	 *************************************************************/
	void GameObject::Shoot(void)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por setar a anima��o de morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::SetDieAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	{
	}

	/*************************************************************
	 * Fun��o que seta o estado atual do ator
	 *
	 *************************************************************/
	void GameObject::SetState(GameObjectState state)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por retornar o estado atual do ator
	 *
	 *************************************************************/
	void GameObject::GetState(GameObjectState &state)
	{		
	}
}
