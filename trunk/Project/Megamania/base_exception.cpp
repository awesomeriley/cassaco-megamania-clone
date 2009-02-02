/******************************************************************
 * Classe que representa a classe base de erro para todas 
 * as classes de exce��o do jogo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *****************************************************************/
#include "base_exception.h"

namespace Megamania
{
	/****************************************************************
	 * Construtor que cria um novo objeto base associando o
	 * mesmo com uma mensagem de erro
	 *
	 * detail -> indica a mensagem de erro 
	 *
	 ***************************************************************/
	Exception::Exception(const char *d) 
	{    
		detail = (d != NULL) ? StringCopy(detail, d) : NULL;
	}

	/*****************************************************************
	 * Fun��o que retorna a mensagem de erro associada com 
	 * o objeto 
	 * 
	 ****************************************************************/
	const char * Exception::GetDetailError()const 
	{    
		return detail;
	}
}