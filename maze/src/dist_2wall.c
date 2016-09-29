#include "maze.h"

int dist_2wall(int p_y, int intersect_y, float p_angle)
{
    int y_dist, diag_dist;

    if (p_angle < 180)
        y_dist = p_y - intersect_y;
    else
        y_dist = intersect_y - p_y;
    
    printf("ydist: %d\n", y_dist);
    
    diag_dist = y_dist / sin(DEGREES_TO_RADIANS(p_angle));
    return (diag_dist);
}