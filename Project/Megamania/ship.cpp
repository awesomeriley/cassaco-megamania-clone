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
#include "ship.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor ~padrão que cria um novo ator, informando 
	 * a animação do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	Ship::Ship(const char *file, Uint16 frameWidth, Uint16 frameHeight)
		throw(SpriteException) : GameObject(file, frameWidth, frameHeight)
	{
		//state = GameObjectState[0];
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo ator
	 *
	 *************************************************************/
	Ship::~Ship(void)
	{
		delete dying;
	}
}
