#include "maze.h"

int comp_dist(int horz_dist, int vert_dist)
{
    if (horz_dist < 0)
        return (vert_dist);
    if (horz_dist < vert_dist || vert_dist < 0)
        return (horz_dist);
    return (vert_dist);
}