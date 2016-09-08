#include "header.h"
#include <string.h>

int init_instance(SDL_Instance *instance, char *win_type)
{
  // int cmp;

  /* Initialize SDL */
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
    return (1);
  }
  /*Create a new Window instance */
  if (strcmp(win_type, "maze") == 0)
  {
    instance->window = SDL_CreateWindow("Dorenstein \\o/", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, 0);
  }
  else if (strcmp(win_type, "map") == 0)
  {
    instance->window = SDL_CreateWindow("Dorenstein Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAP_WIDTH, MAP_HEIGHT, 0);
  }
  else
  {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }
  /* Create a new Renderer instance linked to the Window */
  instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (instance->renderer == NULL)
  {
    SDL_DestroyWindow(instance->window);
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_Quit();
    return (1);
  }
  return (0);
}
