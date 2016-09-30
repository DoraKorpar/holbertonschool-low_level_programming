#include "maze.h"

int main(void)
{
    t_instance instance;
    t_map map;
    t_pov ppov;
    int horz_dist, vert_dist, wall_dist, x_diff;
    float cur_angle;

    if (init_instance(&instance) != 0)
        return (1);
    if (init_maze(&map, &ppov) != 0)
        return (1);
    print_mem(&map, &ppov);
    while (1)
    {
        render_bg(&instance);
        if (poll_events() == 1)
            break;
        // ppov.player_angle += 0.5;
        if (ppov.player_angle >= 360)
            ppov.player_angle -= 360;
        cur_angle = ppov.player_angle + (FOV / 2);
        x_diff = 0;
        while (cur_angle >= (ppov.player_angle - (FOV / 2)))
        {
            if (cur_angle < 0)
                cur_angle += 360;
            if (cur_angle >= 360)
                cur_angle -= 360;
            printf("current angle: %f\n", cur_angle);
            printf("x position on screen: %d\n", x_diff);
            horz_dist = horz_intersect(&map, &ppov, cur_angle);
            vert_dist = vert_intersect(&map, &ppov, cur_angle);
            printf("horizontal distance to wall: %d\n", horz_dist);
            printf("vertical distance to wall: %d\n", vert_dist);
            wall_dist = comp_dist(horz_dist, vert_dist);
            printf("shorter distance to wall: %d\n", wall_dist);
            draw_wall(wall_dist, x_diff, &ppov, &instance);
            cur_angle -= ppov.asr;
            x_diff += 1;
        }
        // ppov.player_angle += 0.01;
        SDL_RenderPresent(instance.renderer);
    }
    kill_maze(&instance);
    return (0);
}