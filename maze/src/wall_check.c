#include "maze.h"

int wall_check(t_map *map, int intersect_x, int intersect_y)
{
    int square_index, square, grid_x, grid_y;

    printf("intersect_y: %d\n", intersect_y);
    printf("intersect_x: %d\n", intersect_x);    

    grid_x = intersect_x / CUBE_SIZE;
    grid_y = intersect_y / CUBE_SIZE;

    square_index = map->width * grid_y + grid_x;
    square = map->map[square_index];
    printf("square (should be 0 or 1): %d\n", square);
    if (square == 0)
        return (0);
    else
        return (1);
}