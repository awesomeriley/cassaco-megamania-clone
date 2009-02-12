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
		surface = LoadImage(defaultImagePath);		
		this->surface->clip_rect.x = x;
		this->surface->clip_rect.y = y;
		validate = new Effect();
		validate->Load(PATH_MENU_VALIDATE);
		text = NULL;
	}

	/*****************************************************
	 * Limpa todas as surfaces inicializadas
	 *****************************************************/
	CSButton::~CSButton()
	{
		SDL_FreeSurface(surface);
		FreeMemory(text);
		delete validate; 
	}

	/****************************************************
	 * Seta a imagem de acordo com a localizacao do mouse 
	 * e tipo do evento. 
	 * Retorna true caso o botao tenha sido clicado com o 
	 * botao direito do mouse, false nos demais casos.
	 ****************************************************/
	bool CSButton::FireChangeImageEvent(SDL_Event* event)
	{
		int x = event->button.x;
		int y = event->button.y;

		//verifica se o ponto passado está contido dentro da área da surface
		if((x >= surface->clip_rect.x) && (x <= surface->clip_rect.x + surface->w) && 
		   (y >= surface->clip_rect.y) && (y <= surface->clip_rect.y + surface->h)) {		   			
			switch(event->type) {
				case SDL_MOUSEBUTTONDOWN:
					if(event->button.button == SDL_BUTTON_LEFT) {
						ChangeState(MENU_BUTTON_DOWN, DOWN);
						validate->Play();
					}
					break;
				case SDL_MOUSEMOTION:
					ChangeState(MENU_BUTTON_MOTION, HIGH_LIGHT);	
					break;
				case SDL_MOUSEBUTTONUP:
					if(event->button.button == SDL_BUTTON_LEFT) {
						ChangeState(MENU_BUTTON_MOTION, HIGH_LIGHT);						
						return true;
					}
					break;					
			}
		} else { 
			ChangeState(MENU_BUTTON, DEFAULT);		
		}	
		return false;
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

			int x = surface->clip_rect.x;
			int y = surface->clip_rect.y;
			SDL_FreeSurface(surface); 
			surface = LoadImage(imagePath);
			surface->clip_rect.x = x;			
			surface->clip_rect.y = y;
		}
	}

	/************************************************************
	 * Função que seta o texto a ser pintado sobre o botão, caso
	 * seja fornecido um ponteiro NULL, nada será pintado
	 * Por default o texto é pintado no centro do botão, para 
	 * modificar a posição do texto, deve-se chamar a função
	 * Megamania::CSButton::SetAlign(V_ALIGNMEMT, H_ALIGNMENT)
	 *
	 ************************************************************/
	void CSButton::SetText(const char *text)
	{
		this->text = StringCopy(this->text, text);
		SetAlign(V_ALIGNMENT::VCENTER, H_ALIGNMENT::HCENTER);
	}

	/************************************************************
	 * Função que seta uma nova fonte a ser aplicada sobre o
	 * texto, caso seja fornecida um ponteiro NULL, o componente
	 * não irá trabalhar corretamente, podendo quebrar o código
	 ************************************************************/
	void CSButton::SetFont(SDL_Font *font) 
	{
		this->font = font;
	}
	
	/**********************************************************
	 * Função que retorna a referencia para a superficie do 
	 * botão
	 **********************************************************/
	SDL_Surface * CSButton::GetSurface(void) 
	{
		return this->surface;
	}

	/**********************************************************
	 * Função responsavel por setar o alinhamento do texto em
	 * relação ao botão, segue abaixo as constantes que pode
	 * ser informadas:
	 * * Alinhamento Vertical
	 *	- TOP
	 *	- VCENTER
	 *	- BOTTOM
	 * * Alinhamento Horizontal
	 *  - LEFT
	 *  - HCENTER
	 *  - RIGHT
	 *
	 **********************************************************/
	void CSButton::SetAlign(V_ALIGNMENT vAlign, H_ALIGNMENT hAlign) 
	{
		int w = 0;
		int h = 0;
		this->font->GetSize(this->text, &w, &h);
		switch(vAlign) {
			case V_ALIGNMENT::TOP:   
				textY = surface->clip_rect.y;
				break;
			case V_ALIGNMENT::VCENTER:
				textY = surface->clip_rect.y + ((surface->clip_rect.h >> 1) - (h >> 1));
				break;
			case V_ALIGNMENT::BOTTOM:
				textY = surface->clip_rect.y + ((surface->clip_rect.h - h));
				break;
		}			
		switch(hAlign) {
			case H_ALIGNMENT::LEFT:
				textX = surface->clip_rect.x;
				break;
			case H_ALIGNMENT::HCENTER:
				textX = surface->clip_rect.x + ((surface->clip_rect.w >> 1) - (w >> 1));
				break;
			case H_ALIGNMENT::RIGHT:
				textX = surface->clip_rect.x + ((surface->clip_rect.w - w));
				break;
		}			
	}

	/**************************************************************
	 * Função responsavel por pintar o botão e texto na superficie
	 * indicada
	 *
	 * background -> indica a superficie onde o botão sera 
	 * pintado
	 *************************************************************/
	void CSButton::Draw(SDL_Surface *background) {
		
		SDL_BlitSurface(surface, NULL, background, &surface->clip_rect);
		if(text != NULL) {
			SDL_Surface *textSurface = font->RenderTextSolid(text);								
			textSurface->clip_rect.x = textX;
			textSurface->clip_rect.y = textY;
			SDL_BlitSurface(textSurface, NULL, background, &textSurface->clip_rect);				
			SDL_FreeSurface(textSurface);
		}
	}

    /********************************************************************
     * Função chamada quando ocorrer algum evento na classe  
	 * MenuScreen
	 *
	 ********************************************************************/
	void CSButton::Action(SDL_Surface *surface) 
	{
		Draw(surface);
	}
}
