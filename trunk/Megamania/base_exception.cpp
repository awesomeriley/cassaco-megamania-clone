/**
 * Classe que representa a classe base de erro para todas 
 * as classes de exce��o do jogo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#include "base_exception.h"

/**
 * Construtor que cria um novo objeto base associando o
 * mesmo com uma mensagem de erro
 *
 * detail -> indica a mensagem de erro 
 *
 */
BaseException::BaseException(std::string &detail) {
    
    this->detail = detail;
}

/**
 * Fun��o que retorna a mensagem de erro associada com 
 * o objeto 
 * 
 */
const std::string & BaseException::getDetailError() {
    
    return detail;
}
