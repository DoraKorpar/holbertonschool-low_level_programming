#include <SDL2/SDL.h>
#include "header.h"

/**
* draw_lines2 - Generates lines going from 3rd to 1st quadrant
* @instance : SDL_Instance
* @num_squares : number of squares grid should have in 1 direction
* @iso_constant : number to multiply iso triangle values by
*
* altitudes 2D array from draw_grid_alt is rotated.
* Function first establishes starting x,y coordinates.
* First loop determines how many lines needed for grid based on num_squares.
* Starting value of x stored in xcopy.
* yalt adds first element of altitudes element to y for each loop.
* Second loop determines how long each grid line needs to be.
* x2 and y2 are end points for each line.
* x2 incremented by same amount every time (see header.h)
* y2 incremented from original y value, changed by iso values and num of loops,
* and then altitude is factored in.
* Line is drawn.
* First points for line (x & yalt) updated until 2nd loop complete.
* x,y of outer loop updated.
*/
void draw_lines2(SDL_Instance instance, int num_squares, int iso_constant)
{
  int i, j;
  float x, y, x2, y2, xcopy, yalt;
  int altitudes[8][8] = {
    {30, 24, 24, 22, 20, 18, 14, 16},
    {20, 10, 10, 10, 10, 4, 10, -10},
    {-10, -10, -10, -10, -8, -20, -20, -30},
    {-20, -20, -18, -14, -40, -20, -20, -30},
    {0, -6, 10, 10, -6, -20, -20, -40},
    {20, 30, 10, 6, -6, -20, -26, -90},
    {40, 20, 30, 30, -10, -40, -90, -110},
    {120, 60, 40, 60, 20, -20, -80, -120}
  };

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
      y2 = y + (ISO_Y * iso_constant * (j + 1)) - altitudes[i][j + 1];

      SDL_RenderDrawLine(instance.renderer, x, yalt, x2, y2);

      x = x2;
      yalt = y2;
      j++;
    }
    ++i;
    x = xcopy + (ISO_X * iso_constant);
    y -= (ISO_Y * iso_constant);
  }
}
