/*****************************************************************
 * Exce��o que representa um erro que ocorre quando
 * se tenta utilizar o sistema de audio sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 ****************************************************************/
#include "audio_exception.h"

namespace Megamania
{
	/*****************************************************************
	 * Construtor padr�o que cria um novo objeto SDLAudioException
	 * associando com uma mensagem de erro
	 ****************************************************************/
	SDLAudioException::SDLAudioException(const char *detail) : Exception(detail) {}
}