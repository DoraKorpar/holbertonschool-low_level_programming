#include "maze.h"

void print_mem(t_map *map, t_pov *ppov)
{
    int row, column, map_num;
    row = 0;
    column = 0;

    printf("map->height = %d\n", map->height);
    printf("map->width = %d\n", map->width);

    printf("map->map:\n");
    while (row < map->height)
    {
        while (column < map->width)
        {
            map_num = *(map->map + row * map->width + column);
            printf("%d ", map_num);
            column++;
        }
        printf("\n");
        column = 0;
        row++;
    }
    printf("ppov->player_x: %f\n", ppov->player_x);
    printf("ppov->player_y: %f\n", ppov->player_y);
    printf("ppov->player_angle: %f\n", ppov->player_angle);
    printf("ppov->dpp: %f\n", ppov->dpp);
    printf("ppov->asr: %f\n", ppov->asr); 
}
