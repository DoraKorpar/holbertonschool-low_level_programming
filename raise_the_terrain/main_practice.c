#include <SDL2/SDL.h>
#include <stdio.h>
#include "header.h"

int main(void)
{
	SDL_Instance instance;
	// int num_squares;
	// int side_ln;

	if (init_instance(&instance) != 0)
		return (1);
	/*
	 * C will always be awesome
	 * This is an infinite loop
	 */
	// printf("Enter how many rows the grid should have (as an integer): ");
	// scanf("%d", &num_squares);
	// printf("Enter your desired side length for each square (an an integer): ");
	// scanf("%d", &side_ln);
	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		/*
		 * Draw some stuff here
		 */
		draw_grid_alt(instance/*, num_squares, side_ln*/);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
