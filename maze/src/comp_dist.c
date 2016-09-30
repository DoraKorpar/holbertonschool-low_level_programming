#include "maze.h"

float comp_dist(float horz_dist, float vert_dist, int *v_or_h)
{
    if (horz_dist < 0)
        return (vert_dist);
    if (horz_dist < vert_dist || vert_dist < 0)
    {
        *v_or_h = 1; /* if v_or_h == 1, will indicate horz_dist was shorter distance */
        return (horz_dist);
    } 
    return (vert_dist);
}