/*****************************************************************
 * Exce��o que representa um erro que ocorre quando
 * se tenta utilizar o sistema TTF sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 ****************************************************************/
#include "font_exception.h"

namespace Megamania
{
	/*****************************************************************
	 * Construtor padr�o que cria um novo objeto SDLFontException
	 * associando com uma mensagem de erro
	 ****************************************************************/
	SDLFontException::SDLFontException(const char *detail) : Exception(detail) {}
}