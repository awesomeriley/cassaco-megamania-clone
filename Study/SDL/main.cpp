#include "SDL.h"
#include "SDL_Image.h"
#include <string>

//Altura da SCR
const int SCR_HEIGHT = 480;

//Largura da SCR
const int SCR_WIDTH = 640;

//Bits Per Pixel
const int SCR_BPP = 32;

//Event Structure
SDL_Event eventOne;

//Imagem de background
SDL_Surface *background = NULL;

//A propria screen
SDL_Surface *screen = NULL; 

//Method to load the image
SDL_Surface *loadImage(std::string fileName)
{
	SDL_Surface *loadedImage = NULL;
	SDL_Surface *optimizedImage = NULL;
	loadedImage = IMG_Load(fileName.c_str());
	
	if (loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	} else {
	    exit(0);
	}
	
	return optimizedImage;
}


void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}


bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return 1;
	}

	screen = SDL_SetVideoMode(SCR_WIDTH, SCR_HEIGHT, SCR_BPP, SDL_SWSURFACE);
		
	if (screen == NULL)
	{
		return 1;
	}
	
	SDL_WM_SetCaption("Event test", NULL);
	
	return true;
}


bool loadFiles()
{
	background = loadImage("c:\\source\\surface.jpg");

	if (background == NULL)
	{
		return false;
	}

	return true;
}


void cleanUp()
{
	SDL_FreeSurface(background);
	SDL_Quit();
}


int main( int argc, char* args[] ) 
{
	bool quit = false;

	if (init() == false)
	{
		return 1;
	}

	if (loadFiles() == false)
	{
		return 1;
	}

	applySurface(0,0,background,screen);

	if (SDL_Flip(screen) == -1)
	{
		return 1;
	}

	while (quit == false)
	{
		while (SDL_PollEvent(&eventOne))
		{
			if (eventOne.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	cleanUp();

	return 0;
}