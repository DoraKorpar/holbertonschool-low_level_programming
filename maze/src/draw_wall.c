#include "maze.h"

void draw_wall(int wall_dist, t_pov *ppov, t_instance *instance)
{
    int y_start, y2;
    float wall_height, x_start, x2;

    wall_height = (CUBE_SIZE / (float)wall_dist) * ppov->dpp;
    printf("wall height: %f\n", wall_height);
    x_start = 0;
    y_start = (WIN_HEIGHT / 2) - (wall_height / 2);
    x2 = x_start + ppov->asr;
    y2 = y_start + wall_height;
    printf("y_start: %d\n", y_start);
    printf("x2: %f\n", x2); 
    printf("y2: %d\n", y2);
    SDL_SetRenderDrawColor(instance->renderer, 255, 0, 0, 128);
    SDL_RenderDrawLine(instance->renderer,
        x_start,
        y_start,
        x2,
        y2
    );
}