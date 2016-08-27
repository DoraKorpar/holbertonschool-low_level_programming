#ifndef _HEADER_H_
#define _HEADER_H_

#include <SDL2/SDL.h>
#include <math.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

#define ISO_Y 1
#define ISO_X (sqrt(3.0))
#define ISO_HYP 2
#define WIN_WIDTH 1260
#define WIN_HEIGHT 720

int init_instance (SDL_Instance *);
int poll_events(void);

#endif
