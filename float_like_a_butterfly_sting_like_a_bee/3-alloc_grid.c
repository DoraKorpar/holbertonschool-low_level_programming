#include <stdlib.h>
/* the idea is to iterate through the arrays at each index of the outer array and assign it to 0, but there's no way to check this yet */
int **alloc_grid(int width, int height) {
  int **outer_grid;
  int i = 0, j = 0;
  outer_grid = malloc(sizeof(int *) * width);

  while (i < width) {
    outer_grid[i] = malloc(sizeof(int) * height);

    while (j < height) {
      outer_grid[i][j] = 0;
      j++;
    }

    i++;
  }
  return (outer_grid);
}
 
  
