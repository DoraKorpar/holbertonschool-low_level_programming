#include "maze.h"

int vert_intersect(t_map *map, t_pov *ppov)
{
    int p_x, p_y, intersect_x, intersect_y;
    float p_angle;
    int delta_x, delta_y, vert_dist;

    printf("vertical distance function\n");
    p_angle = ppov->player_angle + (FOV / 2);
    printf("p_angle: %f\n", p_angle);
    p_x = ppov->player_x * CUBE_SIZE;
    p_y = ppov->player_y * CUBE_SIZE;
    printf("p_y: %d\n", p_y);
    printf("p_x: %d\n", p_x);

    if (p_angle < 90 || p_angle > 270)
    {
        intersect_x = (p_x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
        intersect_y = p_y + (p_x - intersect_x) * tan(DEGREES_TO_RADIANS(p_angle));

        delta_x = CUBE_SIZE;
        delta_y = -(CUBE_SIZE * tan(DEGREES_TO_RADIANS(p_angle)));

        while(wall_check(map, intersect_x, intersect_y) == 0)
        {
            intersect_x += delta_x;
            intersect_y += delta_y;
        }
        vert_dist = dist_2wall(p_y, intersect_y, p_angle);
        return (vert_dist);
    }
    return (0);
}