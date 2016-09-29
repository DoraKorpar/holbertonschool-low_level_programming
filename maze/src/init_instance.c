#include "maze.h"

int init_instance(t_instance *instance)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Unable to initialize instance : %s\n", SDL_GetError());
        return (1);
    }
    instance->window = SDL_CreateWindow(
        "Welcome to Dorenstein",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIN_WIDTH,
        WIN_HEIGHT,
        0
    );
    if (instance->window == NULL)
    {
        fprintf(stderr, "SDL_CreateWindow error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    instance->renderer = SDL_CreateRenderer(
        instance->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (instance->renderer == NULL)
    {
        fprintf(stderr, "SDL_CreateRenderer error: %s\n", SDL_GetError());
        SDL_DestroyWindow(instance->window);
        SDL_Quit();
        return (1);
    }
    return (0);
}