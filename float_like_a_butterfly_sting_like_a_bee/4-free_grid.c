#include <stdlib.h>

/* frees two-dimensional grid */
void free_grid(int **grid, int i) {
  int j;
  for (j = 0; j < i; j++) {
    free(grid[j]);
  }
  free(grid);
}
