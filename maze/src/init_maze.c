#include "maze.h"
#include <stdio.h>

int init_maze(t_map *map, t_pov *ppov)
{
	int temp_map[] = {
		1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1
	};
	int mem_size;

	map->height = 6;
	map->width = 6;
	mem_size = map->height * map->width * sizeof(int);
	map->map = malloc(mem_size);
	if (map->map == NULL)
		return (1);
	memcpy(map->map, temp_map, mem_size);

	ppov->player_x = 2.5;
	ppov->player_y = 1.5;
	ppov->player_angle = 45.0;
	ppov->dpp = ((WIN_WIDTH / 2) / (tan(DEGREES_TO_RADIANS(FOV))));
	ppov->asr = FOV / WIN_WIDTH;
	return (0);
}
