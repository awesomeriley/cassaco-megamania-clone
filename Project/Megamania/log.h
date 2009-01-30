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

#include <string>
#include <stdlib.h>
#include <stdio.h>

namespace Megamania
{
	class Log 
	{    
		private:
			static int level;
			Log(void);
			~Log(void);
		public:
			static const int DEBUG = 0x01; 
			static const int WARN  = 0x02;
			static const int INFO  = 0x03;
			static const int ERROR = 0x04;
		public:
			static void SetLogLevel(int) 
			{	
				if((level >= Log::DEBUG)&&(level <= Log::ERROR)) {
					Log::level = level;
				} else {
					Log::level = Log::INFO;    
				}   
			}
			static std::string GetLogLevel(void) 
			{
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
			static void LogMSG(int, std::string);	         
	};
}

#ifdef LOG
#  define LOG_DEBUG(msg)    Log::LogMSG(Log::DEBUG, msg)
#  define LOG_WARN(msg)     Log::LogMSG(Log::WARN, msg)
#  define LOG_INFO(msg)     Log::LogMSG(Log::INFO, msg)
#  define LOG_ERROR(msg)    Log::LogMSG(Log::ERROR, msg)
#else
#  define LOG_DEBUG(msg)    ((void)0)
#  define LOG_WARN(msg)     ((void)0)
#  define LOG_INFO(msg)     ((void)0)
#  define LOG_ERROR(msg)    ((void)0)
#endif

#endif //__LOG_H__
