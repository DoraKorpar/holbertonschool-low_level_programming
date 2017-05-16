#include "maze.h"

void render_bg(t_instance *instance)
{
	SDL_Rect sky;
	SDL_Rect floor;

	sky.x = 0;
	sky.y = 0;
	sky.w = WIN_WIDTH;
	sky.h = WIN_HEIGHT / 2;
	SDL_SetRenderDrawColor(instance->renderer, 0, 191, 255, 255);
	/* blue sky */
	SDL_RenderFillRect(instance->renderer, &sky);
	
	floor.x = 0;
	floor.y = WIN_HEIGHT / 2;
	floor.w = WIN_WIDTH;
	floor.h = WIN_HEIGHT / 2;
	SDL_SetRenderDrawColor(instance->renderer, 50, 205, 50, 255);
	/* green grass */
	SDL_RenderFillRect(instance->renderer, &floor);
}
