
#define LOG

#include "SDL.h"
#include "initializer.h"
#include "log.h"
#include "splash_screen.h"
#include "game_config.h"

int main(int argc, char **argv) 
{	
	Initializer::Init();
	SplashScreen *splash = new SplashScreen(screen);
	splash->Show();	
	return 0;
}