#include "maze.h"

int dist_2wall(int p_y, int intersect_y, float cur_angle)
{
    float y_dist, diag_dist;

    if (cur_angle <= 180)
        y_dist = p_y - intersect_y;
    else
        y_dist = intersect_y - p_y;
    
    printf("y distance for sine equation: %f\n", y_dist);
    
    diag_dist = (float)y_dist / sin(DEGREES_TO_RADIANS(cur_angle));
    printf("calculated hypotenuse length: %f\n", diag_dist);
    return (diag_dist);
}