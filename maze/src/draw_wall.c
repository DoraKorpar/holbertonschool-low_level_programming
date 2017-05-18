#include "maze.h"

void draw_wall(float wall_dist, int col_num, int v_or_h,
			   float cur_angle, t_pov *ppov, t_instance *instance)
{
	int x;
	float wall_height, y_start, y2, fishbowl;

	if (cur_angle > ppov->player_angle)
		fishbowl = wall_dist *
			cos(DEGREES_TO_RADIANS(cur_angle - ppov->player_angle));
	if (cur_angle < ppov->player_angle)
		fishbowl = wall_dist *
			cos(DEGREES_TO_RADIANS(ppov->player_angle - cur_angle));
	if (cur_angle == ppov->player_angle)
		fishbowl = wall_dist;

	wall_height = (CUBE_SIZE / fishbowl) * ppov->dpp;
	x = col_num;
	y_start = (WIN_HEIGHT / 2) - (wall_height / 2);
	y2 = y_start + wall_height;

	/* wall will run north-south */
	if (v_or_h == 0)
		SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 128);
	/* wall will run east-west */
	if (v_or_h == 1)
		SDL_SetRenderDrawColor(instance->renderer, 250, 250, 0, 128);
	SDL_RenderDrawLine(instance->renderer,
		x,
		y_start,
		x,
		y2
	);
}
