
#include "SDL.h"
#include "initializer.h"
#include "log.h"
#include "splash_screen.h" //faltando!
#include "game_config.h"

#define LOG

int main(int argc, char **argv) {
	
	Initializer::init();
	SplashScreen *splash = new SplashScreen(screen);
	splash->Show();
	return 0;
}