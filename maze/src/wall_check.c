#include "maze.h"

int wall_check(t_map *map, float intersect_x, float intersect_y)
{
	int square_index, square, grid_x, grid_y;

	grid_x = intersect_x / CUBE_SIZE;
	grid_y = intersect_y / CUBE_SIZE;

	square_index = (map->width * grid_y) + grid_x;
	square = map->map[square_index];

	if (grid_x > map->width || grid_y > map->height)
		return (-1);
	if (square == 0)
		return (0);
	else
		return (1);
}
