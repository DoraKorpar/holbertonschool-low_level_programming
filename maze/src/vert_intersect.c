#include "maze.h"

float vert_intersect(t_map *map, t_pov *ppov, float cur_angle)
{
    // int wall_return;
    float p_x, p_y, intersect_x, intersect_y, delta_x, delta_y, vert_dist;

    printf("VERTICAL INTERSECTIONS\n");

    p_x = ppov->player_x * CUBE_SIZE;
    p_y = ppov->player_y * CUBE_SIZE;

    if (cur_angle <= 90 || cur_angle >= 270) /* ray is facing right */
    {
        intersect_x = ((int)(p_x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE);
        // if (delta_x < 0)
            delta_x = CUBE_SIZE;
    }
    else if (cur_angle > 90 && cur_angle < 270) /* ray is facing left */
    {
        intersect_x = ((int)(p_x / CUBE_SIZE) * CUBE_SIZE - 0.0001);
        // if (delta_x > 0)
            delta_x = -CUBE_SIZE;
    }

    intersect_y = p_y + (p_x - intersect_x) * tan(DEGREES_TO_RADIANS(cur_angle));
    delta_y = (CUBE_SIZE * tan(DEGREES_TO_RADIANS(cur_angle)));
    if (cur_angle <= 180) /* ray is facing up */
    {
        if (delta_y > 0)
            delta_y = -delta_y;
    }
    if (cur_angle > 180)
    {
        if (delta_y < 0)
            delta_y = -delta_y;
    }
    if (intersect_y > WIN_WIDTH || intersect_y < 0) /* intersection point exceeds window */
        return (-1);
    if (intersect_x > WIN_HEIGHT || intersect_x < 0)
        return (-1);
    
    while (wall_check(map, intersect_x, intersect_y) == 0)
    {
        intersect_y += delta_y;
        intersect_x += delta_x;
    }
    // wall_return = 0;
    // while (wall_return == 0)
    // {
    //     wall_return = wall_check(map, intersect_x, intersect_y);
    //     if (wall_return == -1)
    //         return (-1);
    //     intersect_y += delta_y;
    //     intersect_x += delta_x;
    // }
    vert_dist = dist_2wall(p_y, intersect_y, cur_angle);
    return (vert_dist);
}