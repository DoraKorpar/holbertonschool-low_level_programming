#include "maze.h"

int main(void)
{
    t_instance instance;
    t_map map;
    t_pov ppov;
    int col_num, v_or_h;
    float horz_dist, vert_dist, wall_dist, cur_angle;

    if (init_instance(&instance) != 0)
        return (1);
    if (init_maze(&map, &ppov) != 0)
        return (1);
    print_mem(&map, &ppov);
    while (1)
    {
        render_bg(&instance);
        if (poll_events(&ppov) == 1)
            break;
		//if (poll_events(&ppov) == 2)
		//	ppov.player_angle += 10.5;
		//if (poll_events() == 3)
		//	ppov.player_angle -= 10.5;
		//if (poll_events() == 4)
		//	col_num = 50;
        // ppov.player_angle += 0.5;
        if (ppov.player_angle > 360)
            ppov.player_angle -= 360;
        cur_angle = ppov.player_angle + (FOV / 2);
        col_num = 0;
        // printf("\tpov player angle: %f\n", ppov.player_angle);
        while (col_num < WIN_WIDTH)
        {
            if (cur_angle <= 0)
                cur_angle += 360;
            if (cur_angle > 360)
                cur_angle -= 360;
            // printf("distance to proj plane: %f\n", ppov.dpp);
            // printf("current angle: %f\n", cur_angle);
            // printf("x position on screen: %d\n", col_num);
            horz_dist = horz_intersect(&map, &ppov, cur_angle);
            vert_dist = vert_intersect(&map, &ppov, cur_angle);
            // printf("horizontal distance to wall: %f\n", horz_dist);
            // printf("vertical distance to wall: %f\n", vert_dist);
            v_or_h = 0;
            wall_dist = comp_dist(horz_dist, vert_dist, &v_or_h);
            // printf("\t\tshorter distance to wall: %f\n", wall_dist);
            // printf("\t\tvertical is 0, horizontal is 1: %d\n", v_or_h);
            draw_wall(wall_dist, col_num, v_or_h,cur_angle, &ppov, &instance);
            cur_angle -= ppov.asr;
            col_num += 1;
            if (col_num > WIN_WIDTH)
                col_num -= WIN_WIDTH;
        }
        SDL_RenderPresent(instance.renderer);
    }
    kill_maze(&instance);
    return (0);
}
