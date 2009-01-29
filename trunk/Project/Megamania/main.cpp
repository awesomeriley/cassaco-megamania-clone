
#define __MEGAMANIA_MAIN_ENTRY_POINT
#ifdef __MEGAMANIA_MAIN_ENTRY_POINT

#define LOG

#include "SDL.h"
#include "initializer.h"
#include "log.h"
#include "menu_screen.h"
#include "game_config.h"

using namespace Megamania;

int main(int argc, char **argv) 
{	
	Initializer::Init();
	MenuScreen *menu = new MenuScreen(screen);
	menu->Show();	
	return 0;
}

#endif