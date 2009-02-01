/*****************************************************************
 * Classe que representa a classe base de erro para todas 
 * as classes de exceção do jogo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
#ifndef __BASE_EXCEPTION_H__
#define __BASE_EXCEPTION_H__

#include "megamania_utils.h"

namespace Megamania 
{
	class Exception 
	{
		protected:
			char *detail;
		public:
			Exception(const char *);  
			virtual ~Exception(void)throw() { FreeMemory(detail); }
			virtual const char * GetDetailError(void)const;
	};
}

#endif //__BASE_EXCEPTION_H__
