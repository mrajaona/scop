#include "angle.h"

float	deg_to_rad(const float angle)
{
	return (angle * (M_PI / 180.0));
}

float	rad_to_deg(const float angle)
{
	return (angle * (180.0 / M_PI));
}