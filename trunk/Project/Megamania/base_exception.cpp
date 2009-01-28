/**
 * Classe que representa a classe base de erro para todas 
 * as classes de exceção do jogo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#include "base_exception.h"
#include <string.h>
#include <stdlib.h>

namespace Megamania
{
	/**
	 * Construtor que cria um novo objeto base associando o
	 * mesmo com uma mensagem de erro
	 *
	 * detail -> indica a mensagem de erro 
	 *
	 */
	Exception::Exception(const char *d) 
	{    
		if(d != NULL) {
			size_t len = strlen(d);
			this->detail = static_cast<char *>(malloc((sizeof(char) * len) + 1));
			memcpy(detail, d, len);
			this->detail[len] = '\0';
		}
	}

	/**
	 * Função que retorna a mensagem de erro associada com 
	 * o objeto 
	 * 
	 */
	const char * Exception::GetDetailError()const 
	{    
		return detail;
	}
}