/*************************************************************
 *
 *
 *
 *
 ************************************************************/
#include "hud.h"
#include "megamania_utils.h"
#include "stdio.h"

/** estrutura utilizada para descobrir o tamanho do Score*/
static int sizeTable[] = { 9, 99, 999, 9999, 99999, 999999 };

namespace Megamania
{

	/*
	 * Inicialização do Singleton da classe
	 */
	HUD * HUD::singleton = NULL;

	/*************************************************************
	 *
	 *
	 ************************************************************/
	HUD::HUD(void)
	{
		panel = LoadImage(PATH_PANEL_HUD);
		shipIcon = LoadImage(PATH_SHIP_ICON);
		SDL_SetColorKey(shipIcon, SDL_SRCCOLORKEY, SDL_MapRGB(shipIcon->format, 0, 0, 0));
		energyBar = LoadImage(PATH_ENERGY_BAR_HUD);
		energyBar2 = LoadImage(PATH_ENERGY_BAR2_HUD);
		bar = LoadImage(PATH_BAR_HUD);
		minP = 0;
		maxP = 999999;
		effect = new Effect();		
		font = new SDL_Font(HUD_FONT, SCORE_FONT_SIZE);
		pointByDecrement = POINT_BY_DECREMENT_HUD;
		point = 0;	
		lifes = 3;
		surface = screen;
		rect.w = panel->clip_rect.w;
		rect.h = panel->clip_rect.h;
		rect.x = 0;
		rect.y = surface->clip_rect.h - rect.h;
		bar->clip_rect.x = BAR_POSITION_X;
		bar->clip_rect.y = BAR_POSITION_Y; 		
		energyBar->clip_rect.y = bar->clip_rect.y;
		energyBar2->clip_rect.x = bar->clip_rect.w - energyBar2->clip_rect.w;
		energyBar2->clip_rect.y = bar->clip_rect.y;
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::SetPoint(int point) 
	{
		this->point = point;
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::IncrementPoint(int inc) 
	{
		this->point += inc;
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::SetLife(int lifes) 
	{
		this->lifes = lifes;
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::IncrementLife(void) 
	{
		++lifes;
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::DecrementLife(void) 
	{
		--lifes;
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::SetOffsetEnergyBar(int)
	{
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::IncrementEnergybar(void)
	{
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::DecrementEnergybar(void)
	{
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::Full(void)
	{
		SDL_BlitSurface(panel, NULL, surface, &rect);
		SDL_BlitSurface(bar, NULL, surface, &bar->clip_rect);
		register int w = bar->clip_rect.w;
		register int offset = energyBar->clip_rect.w;
		int x = bar->clip_rect.x;				
		for(Uint32 i = 0; i < w; i += offset) {
			energyBar->clip_rect.x = x;
			SDL_BlitSurface(energyBar, NULL, surface, &energyBar->clip_rect);	
			SDL_Flip(surface);			
			x += offset;
			SDL_Delay(delay);
		}
		energyBar->clip_rect.x = bar->clip_rect.x;
		surface->clip_rect.h -= rect.h;
	}
	
	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::Empty(void)
	{
		SDL_BlitSurface(panel, NULL, surface, &rect);
		UpdateLife();
		UpdateScore();
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::UpdateLife(void) 
	{		
		int x = shipIcon->clip_rect.w;
		shipIcon->clip_rect.y = rect.y + (rect.h >> 1);
		for(Uint16 i = 0; i < lifes; ++i) {
			shipIcon->clip_rect.x = x;			
			SDL_BlitSurface(shipIcon, NULL, surface, &shipIcon->clip_rect);
			x += shipIcon->clip_rect.w;
		}	
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::UpdateScore(void) 
	{
		if((point >= minP)&&(point <= maxP)) {
			int len = 0;
			for(int i = 0; ; ++i) {
				if(point <= sizeTable[i]) {
				    len = sizeTable[i] + 1;
					break;
				}
			}
			char *buffer = static_cast<char *>(SDL_malloc(sizeof(char) * len));
			sprintf(buffer, "%d", point);
			buffer[len - 1] = '\0';
			SDL_Surface *text = font->RenderTextSolid(static_cast<char *>(buffer));
			text->clip_rect.x = rect.w - text->clip_rect.w;
			text->clip_rect.y = rect.y + rect.h - text->clip_rect.h;
			SDL_BlitSurface(text, NULL, surface, &text->clip_rect);			
			SDL_FreeSurface(text);
			SDL_free(buffer);
		}
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	SDL_Rect & HUD::GetRect(void) 
	{
		return rect;
	}

	/*************************************************************
	 *
	 *
	 ************************************************************/
	void HUD::Draw(void)
	{				
		surface->clip_rect.h += rect.h;
		//SDL_BlitSurface(panel, NULL, surface, &rect);	
		//UpdateScore();
		//UpdateLife();
		SDL_BlitSurface(energyBar2, NULL, surface, &energyBar2->clip_rect);	
		energyBar2->clip_rect.x -= energyBar2->clip_rect.w;
		SDL_Delay(2000);
		surface->clip_rect.h -= rect.h;
	}
}