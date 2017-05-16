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
					if (ppov->player_angle > 45.0 && ppov->player_angle <= 135.0) 
						ppov->player_y -= 0.1;
					else if (ppov->player_angle > 135.0 && ppov->player_angle <= 225.0)
						ppov->player_x -= 0.1;
					else if (ppov->player_angle > 225.0 && ppov->player_angle <= 315.0)
						ppov->player_y += 0.1;
					else if (ppov->player_angle > 315.0 || ppov->player_angle <= 45.0)
						ppov->player_x += 0.1;
					break;
			    case SDLK_s:
					if (ppov->player_angle > 45.0 && ppov->player_angle <= 135.0) 
						ppov->player_y += 0.1;
					else if (ppov->player_angle > 135.0 && ppov->player_angle <= 225.0)
						ppov->player_x += 0.1;
					else if (ppov->player_angle > 225.0 && ppov->player_angle <= 315.0)
						ppov->player_y -= 0.1;
					else if (ppov->player_angle > 315.0 || ppov->player_angle <= 45.0)
						ppov->player_x -= 0.1;
					break;
			    case SDLK_a:
					if (ppov->player_angle > 45.0 && ppov->player_angle <= 135.0) 
						ppov->player_x -= 0.1;
					else if (ppov->player_angle > 135.0 && ppov->player_angle <= 225.0)
						ppov->player_y += 0.1;
					else if (ppov->player_angle > 225.0 && ppov->player_angle <= 315.0)
						ppov->player_x += 0.1;
					else if (ppov->player_angle > 315.0 || ppov->player_angle <= 45.0)
						ppov->player_y -= 0.1;
					break;
			    case SDLK_d:
					if (ppov->player_angle > 45.0 && ppov->player_angle <= 135.0) 
						ppov->player_x += 0.1;
					else if (ppov->player_angle > 135.0 && ppov->player_angle <= 225.0)
						ppov->player_y -= 0.1;
					else if (ppov->player_angle > 225.0 && ppov->player_angle <= 315.0)
						ppov->player_x -= 0.1;
					else if (ppov->player_angle > 315.0 || ppov->player_angle <= 45.0)
						ppov->player_y += 0.1;
					break;
			    case SDLK_ESCAPE:
					return (1);
			}
		}
	}
	return (0);
}
