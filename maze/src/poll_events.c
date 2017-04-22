#include "maze.h"

int poll_events(t_pov *ppov)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
		if (event.type == SDL_QUIT)
			return (1);
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			    case SDLK_LEFT:
					ppov->player_angle += 1;
					break;
			    case SDLK_RIGHT:
					ppov->player_angle -= 1;
					break;
			    case SDLK_w:
					return (4);
			    case SDLK_s:
					return (5);
			    case SDLK_ESCAPE:
					return (1);
			}
		}
    }
    return (0);
}
