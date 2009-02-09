/********************************************************************
 * Classe que marca um dado objeto como sendo interessado em ouvir
 * os eventos disparados pela classe MenuScreen
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 ********************************************************************/
#ifndef __MENU_LISTENER_H__
#define __MENU_LISTENER_H__

namespace Megamania
{
	class MenuScreenListener 
	{
		public:
			virtual ~MenuScreenListener(void) {};
			/********************************************************************
			 * Função chamada quando ocorrer algum evento na classe  
			 * MenuScreen
			 *
			 ********************************************************************/
			virtual void Action(SDL_Surface *) = 0;
	};
}

#endif //__MENU_LISTENER_H__