#include <SDL2/SDL.h>
#include "header.h"

void add_alt(SDL_Instance instance, int num_squares, int iso_constant, int altitudes[][8])
{
  int i, j;
  float x, y, x2, y2, xcopy, yalt;

  i = 0;
  x = 10;
  y = (WIN_HEIGHT / 2) + 50;

  while (i < (num_squares + 1))
  {
    xcopy = x;
    yalt = y - altitudes[i][0];
    j = 0;
    while (j < num_squares)
    {
      x2 = x + (ISO_X * iso_constant);
      y2 = y - (ISO_Y * iso_constant * (j + 1)) - altitudes[i][j + 1];

      SDL_RenderDrawLine(instance.renderer, x, yalt, x2, y2);

      x = x2;
      yalt = y2;
      j++;
    }
    ++i;
    x = xcopy + (ISO_X * iso_constant);
    y += (ISO_Y * iso_constant);
  }
}
