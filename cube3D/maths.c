#include "include_lib.h"

float	rad(float x)
{
	return ((x / 360) * (2 * M_PI));
}

float	normalized(float x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}