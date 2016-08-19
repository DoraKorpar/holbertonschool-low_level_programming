#include <SDL2/SDL.h>
#include "header.h"

void draw_grid_alt(SDL_Instance instance/*, int num_squares, int side_ln*/)
{
  int iso_constant, num_squares, side_ln;
  int altitudes[8][8] = {
    {30, 20, -10, -20, 0, 20, 40, 120},
    {24, 10, -10, -20, -6, 30, 20, 60},
    {24, 10, -10, -18, 10, 10, 30, 40},
    {22, 10, -10, -14, 10, 6, 30, 60},
    {20, 10, -8, -40, -6, -6, -10, 20},
    {18, 4, -20, -20, -20, -20, -40, -20},
    {14, 10, -20, -20, -20, -26, -90, -80},
    {16, -10, -30, -30, -40, -90, -110, -120}
  };

  num_squares = 7;
  side_ln = 80;
  iso_constant = (side_ln / ISO_HYP);

  SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  // draw_lines1(instance, num_squares, iso_constant);
  draw_lines2(instance, num_squares, iso_constant);
  add_alt(instance, num_squares, iso_constant, altitudes);
}
