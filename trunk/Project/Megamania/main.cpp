
#define __MEGAMANIA_MAIN_ENTRY_POINT
#ifdef __MEGAMANIA_MAIN_ENTRY_POINT

#include <cstdlib>
#include "game_controller.h"

#define LOG

using namespace Megamania;

int main(int argc, char **argv) 
{	
	GameController instance = GameController::GetInstance();
	instance.OnGameInit();
	instance.OnGameLoop();
	return EXIT_SUCCESS;
}

#endif