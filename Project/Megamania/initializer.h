/*******************************************************************
 * Classe responsavel por iniciar o sistema SDL, esta classe 
 * deve ser chamada antes de se utilizar qualquer objeto do 
 * SDL.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ******************************************************************/
#ifndef __INITIALIZER_H__
#define __INITIALIZER_H__

namespace Megamania
{
	class Initializer 
	{    
		private:
			Initializer(void);
		public:
			static void Init(void);
			static void Shutdown(void);
	};
}

#endif //__INITIALIZER_H__
