/**
 * Classe responsavel por realizar operações de log
 *  
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 */
#include "log.h"

#ifndef __func__
#define __func__ ""
#endif

/**
 * Função responsavel por logar a mensagem de erro informada
 * bem como o level do log, aqui a mensagem de erro será gravada
 * no stream de erro (stderr).
 *
 * level -> indica o level do log, podendo ser:
 *    - DEBUG
 *    - ERROR
 *    - INFO
 *    - WARN
 * info -> indica a mensagem de erro do objeto
 *
 */

#pragma warning(disable:4996)

void Log::log(int level, std::string info) {
    
    const char *levelDesc = NULL;
    switch(level) {
	    case Log::DEBUG:
	        levelDesc = "DEBUG";
	        break;
	    case Log::WARN:
	        levelDesc = "WARN";
	        break;
	    case Log::INFO:
	        levelDesc = "INFO";
	        break;
	    case Log::ERROR:
	        levelDesc = "ERROR";
	        break;
	    default:
	        levelDesc = "INFO";		        
	        break;
	}	
	fprintf(stderr, "%s %s %s %s %d %s", levelDesc, __FILE__, __DATE__, __func__, __LINE__, info.c_str());
}