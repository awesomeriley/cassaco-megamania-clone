/*******************************************************************
 * Classe responsavel por realizar operações de log,
 * para ativar as operações de log deve-se definir a 
 * macro LOG
 *  
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ******************************************************************/
#ifndef __LOG_H__
#define __LOG_H__

#define LOG
#include <stdio.h>

#ifdef LOG
#  ifndef FILE_LOG_CREATED
#    define FILE_LOG_CREATED
     static FILE *log = fopen("log.log", "a");
#   endif
#endif

#ifndef __func__
#  ifdef _MSC_VER
#    ifdef __FUNCTION__
#      define __func__ __FUNCTION__
#    else
#      define __func__ ""  
#    endif
#  else 
#    define __func__ ""
#  endif
#endif

#define DEBUG "DEBUG" 
#define WARN  "WARN"
#define INFO  "INFO"
#define ERROR "ERROR"

#ifdef LOG
#  define LOG_DEBUG(msg)    fprintf(log, "\n[LEVEL] %s [FILE] %s [DATE] %s [FUNC] %s [LINE] %d %s", DEBUG, __FILE__, __DATE__, __func__, __LINE__, msg)
#  define LOG_WARN(msg)     fprintf(log, "\n[LEVEL] %s [FILE] %s [DATE] %s [FUNC] %s [LINE] %d %s", WARN, __FILE__, __DATE__, __func__, __LINE__, msg)
#  define LOG_INFO(msg)     fprintf(log, "\n[LEVEL] %s [FILE] %s [DATE] %s [FUNC] %s [LINE] %d %s", INFO, __FILE__, __DATE__, __func__, __LINE__, msg)
#  define LOG_ERROR(msg)    fprintf(log, "\n[LEVEL] %s [FILE] %s [DATE] %s [FUNC] %s [LINE] %d %s", ERROR,  __FILE__, __DATE__, __func__, __LINE__, msg)
#else
#  define LOG_DEBUG(msg)    ((void)0)
#  define LOG_WARN(msg)     ((void)0)
#  define LOG_INFO(msg)     ((void)0)
#  define LOG_ERROR(msg)    ((void)0)
#endif

#endif //__LOG_H__
