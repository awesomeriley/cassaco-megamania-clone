/*****************************************************************
 * Exceção que representa um erro caso ocorra
 * algum erro na criação de um objeto Sprite
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ****************************************************************/
#include "sprite_exception.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor padrão que cria um novo objeto SDLVideoException
	 * associando com uma mensagem de erro
	 **************************************************************/
	SpriteException::SpriteException(const char *detail) : Exception(detail) {}
}
