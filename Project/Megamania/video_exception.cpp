/**
 * Exceção que representa um erro que ocorre quando
 * se tenta utilizar o Video sem que o mesmo tenha 
 * sido inicializado corretamente.
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com)
 *
 */
#include "video_exception.h"

SDLVideoException::SDLVideoException(std::string &detail) : BaseException(detail) {
}
