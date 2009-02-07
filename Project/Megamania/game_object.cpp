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
		offset = 0;
	}
	
	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo ator
	 *
	 *************************************************************/
	GameObject::~GameObject(void)
	{
		delete animation;
	}


	/*************************************************************
	 * Fun��o responsavel por setar a anima��o de morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::SetAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException)
	{
		animation = new Sprite(file, frameWidth, frameHeight);
	}
}
