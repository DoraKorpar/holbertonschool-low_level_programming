#include "maze.h"

float dist_2wall(float p_y, float intersect_y, float cur_angle)
{
	float y_dist, diag_dist;

	if (cur_angle <= 180) /* ray is facing up */
		y_dist = p_y - intersect_y;
	else
		y_dist = intersect_y - p_y;

	/* printf("y distance for sine equation: %f\n", y_dist); */
	diag_dist = y_dist / sin(DEGREES_TO_RADIANS(cur_angle));
	if (cur_angle >= 180)
		diag_dist = -diag_dist;
	/* printf("calculated hypotenuse length: %f\n", diag_dist); */
	return (diag_dist);
}
