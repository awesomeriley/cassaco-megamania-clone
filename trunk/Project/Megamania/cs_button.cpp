/***************************************************************
 * Implementação da classe CSButton que nada 
 * mais é do que a representação de um botão 
 * baseado em interfaces GUI.
 *
 * Author Marcelo Costa Collyer (marcelocollyer@gmail.com) 
 **************************************************************/
#include "SDL.h"
#include "game_config.h"
#include "megamania_utils.h"
#include "cs_button.h"

namespace Megamania
{
	/*****************************************************
	 * Construtor padrão que define a imagem e estados 
	 * iniciais e a carrega imagem padrão
	 *****************************************************/
	CSButton::CSButton(char *defaultImagePath, int x, int y)
	{	
		this->defaultImagePath = defaultImagePath;
		surface = LoadImage(defaultImagePath);
		SDL_SetColorKey(surface, SDL_SRCCOLORKEY, SDL_MapRGB(surface->format, 0xff, 0, 0));
		this->surface->clip_rect.x = x;
		this->surface->clip_rect.y = y;
	}

	/*****************************************************
	 * Limpa todas as surfaces inicializadas
	 *****************************************************/
	CSButton::~CSButton()
	{
		defaultImagePath = NULL;
		downImagePath = NULL;
		lightImagePath = NULL;
		surface = NULL;
	}

	/****************************************************
	 * Seta a imagem de acordo com a localizacao do mouse 
	 * e tipo do evento.
	 ****************************************************/
	SDL_Surface* CSButton::FireChangeImageEvent(SDL_Event* event)
	{
		int x = event->button.x;
		int y = event->button.y;

		//verifica se o ponto passado está contido dentro da área da surface
		if((x >= surface->clip_rect.x) && (x <= surface->clip_rect.x + surface->w) && 
		   (y >= surface->clip_rect.y) && (y <= surface->clip_rect.y + surface->h)) {
			
				switch(event->type){
					case SDL_MOUSEBUTTONDOWN:
						ChangeState(MENU_BUTTON_DOWN, DOWN);
						break;
					case SDL_MOUSEMOTION:
						ChangeState(MENU_BUTTON_MOTION, HIGH_LIGHT);
						break;
					case SDL_MOUSEBUTTONUP:
						ChangeState(MENU_BUTTON_MOTION, HIGH_LIGHT);
						break;
					
				}
		} else { 
			ChangeState(MENU_BUTTON, DEFAULT);		
		}
		
		return NULL;
	}

	/****************************************************
	 * Caso o estado passado seja diferente, é setado o 
	 * novo estado e a nova imagem do botão de acordo 
	 * com o evento disparado. Tambem limpa a surface 
	 * antiga da memória.
	 ****************************************************/
	void CSButton::ChangeState(char *imagePath, STATE_ENUM state) 
	{
		if(this->state != state) {
			this->state = state;

			SDL_Rect rect;
			rect.x = surface->clip_rect.x;
			rect.y = surface->clip_rect.y;

			SDL_FreeSurface(surface); 
			surface = LoadImage(imagePath);
			surface->clip_rect.x = rect.x;			
			surface->clip_rect.y = rect.y;

			if(label != NULL && strlen(label)){
			
				WriteText(surface, font, color, label);
			}
		}
	}

	
	/******************************************************
	 * Label, font and color set methods
	 ******************************************************/
	void CSButton::SetLabel(char *label)
	{
		this->label = label;
	}

	void CSButton::SetFont(TTF_Font *font)
	{
		this->font = font;
	}

	void CSButton::SetColor(SDL_Color color){
	
		this->color = color;
	}
}
