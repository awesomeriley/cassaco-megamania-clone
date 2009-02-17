/*************************************************************
 * Classe que representa a classe base para todos os objetos
 * do JOGO, como por exemplo a nave inimiga, a nave principal
 * e a bala, todas as sub-classes devem ter esta classe como
 * a super-classe em sua hierarquia.
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
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
		offsetX = offsetY = 0;
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
	 * Função responsavel por setar a animação de morte do
	 * ator
	 *
	 *************************************************************/
	void GameObject::SetAnimation(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException)
	{
		if(animation != NULL) {
		    delete animation;
		}
		animation = new Sprite(file, frameWidth, frameHeight);
	}

	/***************************************************************
	 * Função que retorna a direcao do objeto
	 *
	 **************************************************************/
	const int GameObject::GetDirection(void)const 
	{	
		return this->direction;
	}
}
