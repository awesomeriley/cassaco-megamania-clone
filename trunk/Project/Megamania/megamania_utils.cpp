/*************************************************************
 * Arquivo que contém varias operações comuns utilizadas pelo
 * projeto MEGAMANIA, aqui são definidos todas as funções	 
 * relacionadas com carregamento de imagens, manipulação de  
 * Strings dentre outras									 
 *															 
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author: Marcelo Collyer
 * Email : marcelocollyer@gmail.com
 *************************************************************/
#include "megamania_utils.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string.h>

/*************************************************************
 * Função responsavel por carregar o icone do Jogo, a imagem 
 * de logo e a mensagem a ser exibida						 
 *************************************************************/
SDL_Surface * LoadImage(const char *file) 
{    
    SDL_Surface *image = NULL;
	if((image = IMG_Load(file)) == NULL) {
	    LOG_ERROR("Erro ao carregar imagen [LoadImage(const char*)]");
		exit(GAME_FATAL_ERROR);
	}
	return SDL_DisplayFormat(image);
}

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
 * dst -> indica o ponteiro onde os dados serão copiados
 * srd -> indica o ponteiro com os dados a copiars
 *
 ********************************************************************/
char * StringCopy(char *dst, const char *src) 
{
	if((src == NULL)||(strlen(src) == 0)) {
	    return dst;
	}
	size_t lenSrc = strlen(src);
	if(dst == NULL) {
	    dst = static_cast<char *>(malloc((sizeof(char) * lenSrc) + 1));
	} else {
	    size_t lenDst = strlen(dst);
		if((lenDst > lenSrc)||(lenDst < lenSrc)) {
		    dst = static_cast<char *>(malloc((sizeof(char) * lenSrc) + 1));
		}
	}
	memcpy(dst, src, lenSrc);
	dst[lenSrc] = '\0';
	return dst;
}

/*********************************************************************
 * Função responsavel por devolver ao sistema a memoria alocado, 
 * esta função somente desaloca memoria alocada por calloc, malloc e
 * realloc, não devendo ser chamada com um ponteiro alocado por new ou
 * por algum objeto Allocator da biblioteca padrão, caso isso ocorra
 * o comportamento da função é indeterminado
 *
 ********************************************************************/
void FreeMemory(void *pointer) 
{
	if(pointer != NULL) {
	    free(pointer);
	}
}