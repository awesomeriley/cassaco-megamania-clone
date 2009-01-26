/**
 * Classe responsavel por realizar operações de log
 *  
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 */
#ifndef __LOG_H__
#define __LOG_H__

#include <string>
#include <stdlib.h>
#include <stdio.h>


class Log { 
    
    private:
       static int level;
       static const int DEBUG = 1; 
       static const int WARN  = 2;
       static const int INFO  = 3;
       static const int ERROR = 4;
       Log(void);
       ~Log(void);
    public:
		static void setLogLevel(int) {	
            if((level >= Log::DEBUG)&&(level <= Log::ERROR)) {
                Log::level = level;
            } else {
                Log::level = Log::INFO;    
	        }   
        }
		static std::string getLogLevel(void) {
            switch(Log::level) {
	            case Log::DEBUG:
	                return "DEBUG";
				case Log::WARN:
			        return "WARN";
	            case Log::INFO:
			        return "INFO";
	            case Log::ERROR:
			        return "ERROR";
	            default:
				    return "INFO";		        
			}
		}
        static void log(int, std::string);	         
};

#ifdef LOG
#  define LOG_DEBUG(msg);    Log::log(Log::DEBUG, msg);
#  define LOG_WARN(msg);     Log::log(Log::WARN, msg);
#  define LOG_INFO(msg);     Log::log(Log::INFO, msg);
#  define LOG_ERROR(msg);    Log::log(Log::ERROR, msg);
#else
#  define LOG_DEBUG(msg);
#  define LOG_WARN(msg);
#  define LOG_INFO(msg);
#  define LOG_ERROR(msg);
#endif

#endif //__LOG_H__
