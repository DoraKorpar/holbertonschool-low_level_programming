#include "maze.h"

void draw_wall(int wall_dist, int x_diff, t_pov *ppov, t_instance *instance)
{
    int y_start, y2, x;
    float wall_height;

    // fishbowl = wall_dist * cos(DEGREES_TO_RADIANS(FOV / 2));
    printf("are we in the draw function\n");
    printf("wall_dist: %d\n", wall_dist);
    wall_height = (CUBE_SIZE / (float)wall_dist) * ppov->dpp;
    printf("wall_height: %f\n", wall_height);
    printf("distance to proj plane: %d\n", ppov->dpp);
    x = x_diff;
    y_start = (WIN_HEIGHT / 2) - (wall_height / 2);
    y2 = y_start + wall_height;
    printf("y u no draw\n");
    printf("x: %d\n", x);
    printf("y_start: %d\n", y_start);
    printf("y2: %d\n", y2);
    SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 128);
    SDL_RenderDrawLine(instance->renderer,
        x,
        y_start,
        x,
        y2
    );
}