
#define __MEGAMANIA_MAIN_ENTRY_POINT
#ifdef __MEGAMANIA_MAIN_ENTRY_POINT

#include <cstdlib>
#include "game_controller.h"

using namespace Megamania;

#ifdef DEBUG_MEMORY    //descomente essa linha para debugar o gerenciamento de memoria

#include "log.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 5

static int new_c = 1;
static int del_c = 1;
static char buffer[BUF_SIZE];
static char buffer0[BUF_SIZE*5];

#ifdef delete
#undef delete
#endif

inline void * operator new(size_t size) {

	memset(buffer, 0, BUF_SIZE);
	memset(buffer0, 0, BUF_SIZE*5);
	sprintf(buffer, "%d", new_c);
	sprintf(buffer0, "%s%s%s", "Operador NEW chamado ", buffer, " vezes");
	LOG_INFO(buffer0);
	new_c++;
	return (void *)malloc(size);
}

inline void operator delete(void *p) {

	memset(buffer, 0, BUF_SIZE);
	memset(buffer0, 0, BUF_SIZE*5);
	sprintf(buffer, "%d", del_c);
	sprintf(buffer0, "%s%s%s", "Operador DELETE chamado ", buffer, " vezes");
	LOG_INFO(buffer0);
	del_c++;
	free(p);
}

#endif

int main(int argc, char **argv) 
{	
	GameController instance = GameController::GetInstance();
	instance.OnGameInit();
	instance.OnGameLoop();
	return EXIT_SUCCESS;
}

#endif