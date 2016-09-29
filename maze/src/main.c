#include "maze.h"

int main(void)
{
    t_instance instance;
    t_map map;
    t_pov ppov;
    int horz_dist, vert_dist, wall_dist;

    if (init_instance(&instance) != 0)
        return (1);
    if (init_maze(&map, &ppov) != 0)
        return (1);
    // print_mem(&map, &ppov);
    while (1)
    {
        render_bg(&instance);
        if (poll_events() == 1)
            break;
        horz_dist = horz_intersect(&map, &ppov);
        printf("horizontal distance: %d\n", horz_dist);
        vert_dist = vert_intersect(&map, &ppov);
        printf("vertical distance: %d\n", vert_dist);
        wall_dist = comp_dist(horz_dist, vert_dist);
        printf("final distance: %d\n", wall_dist);
        draw_wall(wall_dist, &ppov, &instance);
        SDL_RenderPresent(instance.renderer);
    }
    kill_maze(&instance);
    return (0);
}