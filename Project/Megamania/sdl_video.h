/**
 *
 *
 *
 *
 *
 *
 *
 *
 */
#ifndef __SDL_VIDEO_H__
#define __SDL_VIDEO_H__

#include "video_exception.h"

class SDLVideo 
{
	private:
		static SDLVideo *uniqueInstance;
		SDL_Surface *screen;
		SDLVideo(void)throw(SDLVideoException) 
		{
		    if(SDL_WasInit(SDL_INIT_VIDEO) != 0) {
			    if((SDL_Init(SDL_INIT_VIDEO)) == -1) {
				}
			}	
		}
	public:
		static const SDLVideo * GetInstance(void)throw(SDLVideoException)
		{
			if(uniqueInstance == NULL) {
				uniqueInstance = new SDLVideo();
			}
			return uniqueInstance;
		}
         
};

#endif //__SDL_VIDEO_H__