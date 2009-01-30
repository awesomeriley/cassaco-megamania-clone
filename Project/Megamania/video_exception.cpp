/*****************************************************************
 * Exce��o que representa um erro que ocorre quando
 * se tenta utilizar o Video sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ****************************************************************/
#include "video_exception.h"

namespace Megamania
{
	/***************************************************************
	 * Construtor padr�o que cria um novo objeto SDLVideoException
	 * associando com uma mensagem de erro
	 **************************************************************/
	SDLVideoException::SDLVideoException(const char *detail) : Exception(detail) {}
}