#include "header.h"

int main(void)
{
	SDL_Instance instance;
	SDL_Renderer *ir;

	if (init_instance(&instance) != 0)
		return (1);
	while (1)
	{
		ir = instance.renderer;
		SDL_SetRenderDrawColor(ir, 0, 191, 255, 255);
		SDL_RenderClear(ir);
		if (poll_events() == 1)
			break;
		// test_draw(instance);
		SDL_Rect floor = {0, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT / 2};
		SDL_SetRenderDrawColor(ir, 50, 205, 50, 255);
		SDL_RenderFillRect(ir, &floor);
		SDL_Rect wall = {380, 185, 500, 350};
		SDL_SetRenderDrawColor(ir, 169, 169, 169, 255);
		SDL_RenderFillRect(ir, &wall);
		// SDL_SetRenderDrawColor(ir, 0xFF, 0xFF, 0xFF, 0xFF);
		// SDL_RenderDrawLine(ir, 50, 50, 50, 500);
		SDL_RenderPresent(ir);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
