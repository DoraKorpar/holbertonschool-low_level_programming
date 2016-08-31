#include <stdio.h>
#include <SDL2/SDL.h>
#include "header.h"

int parse_maze(SDL_Instance instance);

int main(void)
{
  SDL_Instance instance;

  if (init_instance(&instance) != 0)
    return (1);
  while (1)
  {
    SDL_SetRenderDrawColor(instance.renderer, 0, 191, 255, 255);
    SDL_RenderClear(instance.renderer);
    if (poll_events() == 1)
      break;
    parse_maze(instance);
    SDL_RenderPresent(instance.renderer);
  }
  SDL_DestroyRenderer(instance.renderer);
  SDL_DestroyWindow(instance.window);
  SDL_Quit();
  return (0);
}

int parse_maze(SDL_Instance instance)
{
  FILE *fp;
  int c, row_num, col_num;

  row_num = 0;
  col_num = 0;
  fp = fopen("maze", "r");
  if (!fp)
    return (1);
  while (!feof(fp))
  {
    c = fgetc(fp);
    SDL_Rect wall = {col_num * 64, row_num * 64, 64, 64};
    SDL_Rect space = {col_num * 64, row_num * 64, 64, 64};
    switch (c) {
      case 10: /* when c is end of line */
        row_num += 1;
        col_num = -1;
        break;
      case 120: /* when c is 'x' */
        SDL_SetRenderDrawColor(instance.renderer, 105, 105, 105, 255);
        SDL_RenderFillRect(instance.renderer, &wall);
        break;
      case 45: /* when c is '-' */
        SDL_SetRenderDrawColor(instance.renderer, 192, 192, 192, 255);
        SDL_RenderFillRect(instance.renderer, &space);
        break;
      default:
        break;
    }
    col_num++;
  }
  fclose(fp);
  return (0);
}
