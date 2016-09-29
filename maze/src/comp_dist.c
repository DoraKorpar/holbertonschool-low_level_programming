#include "maze.h"

int comp_dist(int horz_dist, int vert_dist)
{
    if (horz_dist < vert_dist)
        return (horz_dist);
    return (vert_dist);
}