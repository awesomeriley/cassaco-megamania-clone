/*************************************************************
 * Arquivo que cont�m varias opera��es comuns utilizadas pelo
 * projeto MEGAMANIA, aqui s�o definidos todas as fun��es	 
 * relacionadas com carregamento de imagens, manipula��o de  
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
 * Fun��o responsavel por carregar o icone do Jogo, a imagem 
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
 * dst -> indica o ponteiro onde os dados ser�o copiados
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
 * Fun��o responsavel por devolver ao sistema a memoria alocado, 
 * esta fun��o somente desaloca memoria alocada por calloc, malloc e
 * realloc, n�o devendo ser chamada com um ponteiro alocado por new ou
 * por algum objeto Allocator da biblioteca padr�o, caso isso ocorra
 * o comportamento da fun��o � indeterminado
 *
 ********************************************************************/
void FreeMemory(void *pointer) 
{
	if(pointer != NULL) {
	    free(pointer);
	}
}