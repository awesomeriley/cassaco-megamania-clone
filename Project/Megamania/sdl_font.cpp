/**********************************************************************
 * Classe responsavel por manipular os dados relacionados com 
 * os sons do jogo , bem como a musica.
 * Esta classe possui operações básicas com tocar um som, uma musica
 * realizar operações de FADE, aumentar e diminuir o volume do som
 * ou música e pausar.
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 *********************************************************************/
#include "sdl_font.h"
#include <string.h>

namespace Megamania
{

	/******************************************************************
	 * Construtor padrão responsavel por criar uma nova Font carregando
	 * os dados do arquivo .ttf informado
	 *
	 * file -> caminho para o arquivo .ttf
	 * size -> indica o tamanho da fonte
	 *
	 ******************************************************************/
	SDL_Font::SDL_Font(const char *file, Uint16 size)throw(SDLFontException)
	{
		if(file == NULL) {
			throw SDLFontException("O objeto Font não pode ser criado, [PATH NULL]");
		}
		if((font = TTF_OpenFont(file, size)) == NULL) {
			throw SDLFontException("O objeto Font não pode ser criado");
		}
		color.r = color.g = color.b = 0xff;    //branco
	}

	/******************************************************************
	 * Destruidor responsavel por desalocar os recursos alocados pelo 
	 * sistema TTF
	 *
	 ******************************************************************/
	SDL_Font::~SDL_Font(void)
	{
		TTF_CloseFont(font);
		font = NULL;
	}

	/******************************************************************
	 * Função responsavel por retornar a surface com o texto informado
	 *
	 * text -> indica o texto a ser renderizado na superficie, caso
	 * seja passado como parametro um valor NULL será retornado uma
	 * superficie NULL
	 * SDL_Surface -> superficie retornada com o texto, ou null caso 
	 * ocorra algum erro
	 *
	 ******************************************************************/
	SDL_Surface * SDL_Font::RenderTextSolid(const char *text) 
	{
		if((text != NULL)&&(strlen(text))) {
			return SDL_DisplayFormat(TTF_RenderText_Solid(font, text, color));
		}
		return NULL;
	}

	/******************************************************************
	 * Função responsavel por retornar o valor indicando a altura da
	 * font
	 *
	 * int -> indica a altura da fonte em pixels
	 *
	 ******************************************************************/
	const int SDL_Font::GetHeight()const
	{
		return TTF_FontHeight(font);
	}

	/******************************************************************
	 * Função responsavel por setar a cor responsavel por pintar
	 * a font
	 *
	 * r -> indica o tom vermelho da cor
	 * g -> indica o tom verde da cor 
	 * b -> indica o tom azul da cor
	 *
	 ******************************************************************/
	void SDL_Font::SetColor(Uint8 r, Uint8 g, Uint8 b) 
	{
		color.r = r;
		color.g = g;
		color.b = b;
	}

	/******************************************************************
	 * Função responsavel por retornar o valor da cor atual aplicada
	 * a font
	 *
	 * r -> variavel que será preenchida com o tom vermelho
	 * g -> variavel que será preenchida com o tom verde
	 * b -> variavel que será preenchida com o tom azul
	 *
	 ******************************************************************/
	void SDL_Font::GetColor(Uint8 &r, Uint8 &g, Uint8 &b)
	{
		r = color.r;
		g = color.g;
		b = color.b;
	}

	/******************************************************************
	 * Função responsavel por retornar o tamando do text informado,
	 * caso o texto informado seja NULL, o valor para a largura e
	 * altura será zero
	 *
	 * text -> indica o texto que terá seu tamanho retornado
	 * w -> variavel que será preenchida com a largura do text
	 * h -> variavel que será preenchida com a altura do text
	 *
	 ******************************************************************/
	void SDL_Font::GetSize(const char *text, int *w, int *h) 
	{
		if((text != NULL)&&(strlen(text))) {
			TTF_SizeText(font, text, w, h);	
		} else {
			*w = *h = 0;
		}
	}
}