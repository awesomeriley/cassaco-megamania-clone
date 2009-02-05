/*************************************************************
 * Arquivo que cont�m varias opera��es comuns utilizadas pelo
 * projeto MEGAMANIA, aqui s�o definidos todas as fun��es	 
 * relacionadas com carregamento de imagens, manipula��o de  
 * Strings dentre outras									 
 *															 
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Co-Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
 *************************************************************/
#ifndef __MEGAMANIA_UTILS_H__
#define __MEGAMANIA_UTILS_H__

#include "game_config.h"

/*************************************************************
 * Fun��o responsavel por carregar o icone do Jogo, a imagem 
 * de logo e a mensagem a ser exibida						 
 *************************************************************/
SDL_Surface * LoadImage(const char *);

/*********************************************************************
 * Fun��o responsavel por copiar os dados do segundo ponteiro
 * para o primeiro, caso o primeiro ponteiro seja NULL, ser� 
 * alocado espa�o do tamanho do segundo ponteiro, caso o primeiro 
 * seja menor ou maior que o segundo ser� realocado espa�o para o 
 * tamanho do segundo ponteiro, evitando assim desperdicio de memoria
 * caso o segundo ponteiro seja NULL, nada ser� copiado para o primeiro
 * e o mesmo ponteiro ser� ser� retornado.
 * Caso os ponteiros se sobreponham o comportamento desta fun��o �
 * indefinidas
 *
 ********************************************************************/
char * StringCopy(char *, const char *);

/*********************************************************************
 * Fun��o responsavel por devolver ao sistema a memoria alocado, 
 * esta fun��o somente desaloca memoria alocada por calloc, malloc e
 * realloc, n�o devendo ser chamada com um ponteiro alocado por new ou
 * por algum objeto Allocator da biblioteca padr�o, caso isso ocorra
 * o comportamento da fun��o � indeterminado
 *
 ********************************************************************/
void FreeMemory(void *);

#endif //__MEGAMANIA_UTILS_H__