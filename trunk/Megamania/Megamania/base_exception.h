/**
 * Classe que representa a classe base de erro para todas 
 * as classes de exceção do jogo
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __BASE_EXCEPTION_H__
#define __BASE_EXCEPTION_H__

#include <string>

class BaseException {
    protected:
	    std::string detail;
	public:
        BaseException(std::string&);  
		virtual ~BaseException(void) {}
        const std::string& getDetailError(void);
};

#endif //__BASE_EXCEPTION_H__
