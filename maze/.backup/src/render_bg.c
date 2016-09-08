#include "header.h"

void render_bg(SDL_Instance instance)
{
  SDL_SetRenderDrawColor(instance.renderer, 0, 191, 255, 255); /* blue sky */
  SDL_RenderClear(instance.renderer);
  SDL_Rect floor = {0, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT / 2};
  SDL_SetRenderDrawColor(instance.renderer, 50, 205, 50, 255); /* green grass */
  SDL_RenderFillRect(instance.renderer, &floor);
}
