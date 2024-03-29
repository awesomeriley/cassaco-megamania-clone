/*****************************************************************
 * Classe que representa a barra de status do jogo, aqui s�o
 * visualizados o timer do jogo, as vidas e os respectivos 
 * pontos adquiridos
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
#include "hud.h"
#include "megamania_utils.h"
#include "stdio.h"

/** estrutura utilizada para descobrir o tamanho do Score*/
static int sizeTable[] = { 9, 99, 999, 9999, 99999, 999999 };

namespace Megamania
{

	/*
	 * Inicializa��o do Singleton da classe
	 */
	HUD * HUD::singleton = NULL;

	/*************************************************************
	 * Construtor default, que inicializa todas as informa��es
	 * necessarias ao Objeto HUD
	 *
	 ************************************************************/
	HUD::HUD(void)
	{
		panel = LoadImage(PATH_PANEL_HUD);
		shipIcon = LoadImage(PATH_SHIP_ICON);
		SDL_SetColorKey(shipIcon, SDL_SRCCOLORKEY, SDL_MapRGB(shipIcon->format, 0, 0, 0));
		energyBar = LoadImage(PATH_ENERGY_BAR_HUD);
		energyBar2 = LoadImage(PATH_ENERGY_BAR2_HUD);
		minP = 0;
		maxP = 999999;
		effect = new Effect();		
		effect->Load(EFFECT_HUD);
		font = new SDL_Font(HUD_FONT, SCORE_FONT_SIZE);
		pointByDecrement = POINT_BY_DECREMENT_HUD;
		point = lifes = 0;	
		surface = screen;
		clipRect.x = clipRect.y = 0;
		clipRect.w = surface->clip_rect.w;
		clipRect.h = surface->clip_rect.h - panel->clip_rect.h;
		rect.w = panel->clip_rect.w;
		rect.h = panel->clip_rect.h;
		rect.x = 0;
		rect.y = surface->clip_rect.h - rect.h;
		energyBar->clip_rect.y = BAR_POSITION_Y;
		energyBar2->clip_rect.y = BAR_POSITION_Y;
	}

	/*************************************************************
	 * Fun��o que seta a pontua��o a ser exibida
	 *
	 ************************************************************/
	void HUD::SetPoint(int point) 
	{
		this->point = point;
	}
	
	/*************************************************************
	 * Fun��o que incrementa a pontua��o atual com o valor 
	 * informado
	 *
	 ************************************************************/
	void HUD::IncrementPoint(int inc) 
	{
		this->point += inc;		
		SDL_SetClipRect(surface, NULL);
		UpdateScore();
		SDL_SetClipRect(surface, &clipRect);
	}

	/*************************************************************
	 * Fun��o que seta a quantidade de vidas a ser exibida
	 *
	 ************************************************************/
	void HUD::SetLife(int lifes) 
	{
		this->lifes = lifes;
	}

	/*************************************************************
	 * Fun��o que retorna a quantidade corrente de vidas que o
	 * Objeto HUD cont�m
	 *
	 ************************************************************/
	int HUD::GetLife(void) 
	{
		return this->lifes;
	}
	
	/*************************************************************
	 * Fun��o que incrementa a quantidade de vida em um
	 *
	 ************************************************************/
	void HUD::IncrementLife(void) 
	{
		++lifes;
	}
	
	/*************************************************************
	 * Fun��o que decrementa a quantidade de vida em um
	 *
	 ************************************************************/
	void HUD::DecrementLife(void) 
	{
		--lifes;
	}
	
	/*************************************************************
	 * Fun��o responsavel por resetar todos os dados do
	 * componente HUD
	 *
	 ************************************************************/
	void HUD::Reset(void) 
	{
		SetLife(INITIAL_LIFE);
		SetPoint(0);
	}
	
	/*************************************************************
	 * Fun��o responsavel por encher a barra de energias
	 * Esta fun��o utiliza um objeto SDL_Rect auxiliar para a 
	 * realiza��o da anima��o e n�o a propria estrutura definida 
	 * no objeto SDL_Surface, para evitar que a aplica��o trave
	 * durante a anima��o
	 *
	 ************************************************************/
	void HUD::Full(void)
	{
		SDL_SetClipRect(surface, NULL);
		SDL_BlitSurface(panel, NULL, surface, &rect);
		UpdateLife();
		UpdateScore();
		register int offset = energyBar->clip_rect.w;
		effect->Play();		
		SDL_Rect rect;    
		rect.x = BAR_POSITION_X; 
		rect.y = energyBar->clip_rect.y;
		rect.w = energyBar->clip_rect.w;
		rect.h = energyBar->clip_rect.h;		
		for(Uint32 i = 0; i < BAR_WITDH; i += offset) {
			SDL_BlitSurface(energyBar, NULL, surface, &rect);	
			SDL_Flip(surface);					
			rect.x += offset;			
			SDL_Delay(delay);            			
		}		
		cursor = BAR_WITDH + BAR_POSITION_X;
		energyBar->clip_rect.x = BAR_POSITION_X;		
		energyBar2->clip_rect.x = BAR_WITDH - energyBar2->clip_rect.w;		
		SDL_SetClipRect(surface, &clipRect);		
	}
	
	void HUD::Empty(void) 
	{
		SDL_SetClipRect(surface, NULL);		
		SDL_Rect rect;
		rect.w = energyBar2->clip_rect.w;
		rect.h = energyBar2->clip_rect.h;
		rect.x = cursor;
		rect.y = BAR_POSITION_Y;
		register int offset = energyBar2->clip_rect.w;
		for(Uint32 i = cursor; i >= BAR_POSITION_X; i -= rect.w) {
			SDL_BlitSurface(energyBar2, NULL, surface, &rect);	
			//N�o usar HUD::IncrementPoint(int);
			this->point += POINT_BY_DECREMENT_HUD;
			UpdateScore();
			SDL_Flip(surface);					
			rect.x -= offset;			
			SDL_Delay(delay);            				
		}
		cursor = BAR_POSITION_X;
	}

	/*************************************************************
	 * Fun��o que pinta a quantidade de vidas no painel
	 *
	 ************************************************************/
	void HUD::UpdateLife(void) 
	{		
		int x = BAR_POSITION_X;						
		shipIcon->clip_rect.y = rect.y + (rect.h >> 1);
		for(Uint16 i = 0; i < lifes; ++i) {
			shipIcon->clip_rect.x = x;			
			SDL_BlitSurface(shipIcon, NULL, surface, &shipIcon->clip_rect);
			x += shipIcon->clip_rect.w;
		}	
	}

	/*************************************************************
	 * Fun��o que pinta o score no painel
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
			char *buffer = reinterpret_cast<char *>(SDL_malloc(sizeof(char) * len));
			sprintf(buffer, "%d", point);
			buffer[len - 1] = '\0';
			SDL_Surface *text = font->RenderTextSolid(reinterpret_cast<const char *>(buffer));
			SDL_Rect r;
			r.x = panel->clip_rect.w - text->clip_rect.w;
			r.y = rect.y + panel->clip_rect.h - text->clip_rect.h;
			r.w = text->clip_rect.w; 
			r.h = text->clip_rect.h;					
			SDL_FillRect(surface, &r, SDL_MapRGB(surface->format, 0, 0, 0));
			SDL_BlitSurface(text, NULL, surface, &r);				
			SDL_FreeSurface(text);
			SDL_free(buffer);
		}		
	}

	/*************************************************************
	 * Fun��o que retorna a posi��o do painel
	 *
	 ************************************************************/
	SDL_Rect & HUD::GetRect(void) 
	{
		return rect;
	}

	/*************************************************************
	 * Fun��o responsavel por pintar o painel na surface
	 *
	 ************************************************************/
	bool HUD::Draw(void)
	{						
		SDL_SetClipRect(surface, NULL);
		SDL_Rect rect;
		rect.w = energyBar2->clip_rect.w;
		rect.h = energyBar2->clip_rect.h;
		rect.x = cursor - rect.w;
		rect.y = BAR_POSITION_Y;
		cursor -= rect.w;
		SDL_BlitSurface(energyBar2, NULL, surface, &rect);
		SDL_UpdateRect(surface, rect.x, rect.y, rect.w, rect.h);
		SDL_SetClipRect(surface, &clipRect);
		return rect.x == BAR_POSITION_X;
	}
}