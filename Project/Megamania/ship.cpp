/*************************************************************
 * Classe base para todas os objetos que representam uma nave
 * no jogo, todas as classes que s�o naves devem ter esta
 * classe como super-classe
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
 *************************************************************/
#include "ship.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor ~padr�o que cria um novo ator, informando 
	 * a anima��o do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	Ship::Ship(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException) : GameObject(file, frameWidth, frameHeight)
	{
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo ator
	 *
	 *************************************************************/
	Ship::~Ship(void)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a anima��o da morte do
	 * ator
	 *
	 *************************************************************/
	void Ship::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a a��o de atirar
	 *
	 *************************************************************/
	void Ship::Shoot(void)
	{
	}

	/*************************************************************
	 * Fun��o que seta o estado atual do ator
	 *
	 *************************************************************/
	void Ship::SetState(ShipState state)
	{
		this->state =  state;
	}

	/*************************************************************
	 * Fun��o responsavel por retornar o estado atual do ator
	 *
	 *************************************************************/
	void Ship::GetState(ShipState &state)
	{
		state = this->state;
	}
}
