#include "header.h"

int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance, "maze") != 0)
		return (1);
	while (1)
	{
		render_bg(instance);
		if (poll_events() == 1)
			break;
		SDL_Rect wall = {380, 185, 500, 350};
		SDL_SetRenderDrawColor(instance.renderer, 169, 169, 169, 255);
		SDL_RenderFillRect(instance.renderer, &wall);
		// SDL_SetRenderDrawColor(ir, 0xFF, 0xFF, 0xFF, 0xFF);
		// SDL_RenderDrawLine(ir, 50, 50, 50, 500);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
