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
	 * Construtor ~padrão que cria um novo ator, informando 
	 * a animação do mesmo, a largura e altura de cada frame
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
	 * Função responsavel por realizar a animação da morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Função responsavel por realizar a ação de atirar
	 *
	 *************************************************************/
	void GameObject::Shoot(void)
	{
	}

	/*************************************************************
	 * Função responsavel por setar a animação de morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::SetDieAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	{
	}

	/*************************************************************
	 * Função que seta o estado atual do ator
	 *
	 *************************************************************/
	void GameObject::SetState(GameObjectState state)
	{
	}

	/*************************************************************
	 * Função responsavel por retornar o estado atual do ator
	 *
	 *************************************************************/
	void GameObject::GetState(GameObjectState &state)
	{		
	}
}
