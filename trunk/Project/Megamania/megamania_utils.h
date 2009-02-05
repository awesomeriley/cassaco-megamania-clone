/*************************************************************
 * Arquivo que contém varias operações comuns utilizadas pelo
 * projeto MEGAMANIA, aqui são definidos todas as funções	 
 * relacionadas com carregamento de imagens, manipulação de  
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
 * Função responsavel por carregar o icone do Jogo, a imagem 
 * de logo e a mensagem a ser exibida						 
 *************************************************************/
SDL_Surface * LoadImage(const char *);

/*********************************************************************
 * Função responsavel por copiar os dados do segundo ponteiro
 * para o primeiro, caso o primeiro ponteiro seja NULL, será 
 * alocado espaço do tamanho do segundo ponteiro, caso o primeiro 
 * seja menor ou maior que o segundo será realocado espaço para o 
 * tamanho do segundo ponteiro, evitando assim desperdicio de memoria
 * caso o segundo ponteiro seja NULL, nada será copiado para o primeiro
 * e o mesmo ponteiro será será retornado.
 * Caso os ponteiros se sobreponham o comportamento desta função é
 * indefinidas
 *
 ********************************************************************/
char * StringCopy(char *, const char *);

/*********************************************************************
 * Função responsavel por devolver ao sistema a memoria alocado, 
 * esta função somente desaloca memoria alocada por calloc, malloc e
 * realloc, não devendo ser chamada com um ponteiro alocado por new ou
 * por algum objeto Allocator da biblioteca padrão, caso isso ocorra
 * o comportamento da função é indeterminado
 *
 ********************************************************************/
void FreeMemory(void *);

#endif //__MEGAMANIA_UTILS_H__