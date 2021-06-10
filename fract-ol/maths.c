#include "includes.h"

float	rad(float x)
{
	return ((x / 360) * (2 * M_PI));
}

float	deg(float x)
{
	return (x / (2 * M_PI) * 360);
}

float	normalized(float x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

float	bornes(float x, float inf, float sup)
{
	if (x > sup)
		return (sup);
	if (x < inf)
		return (inf);
	return (x);
}

void	cart_pol(float *r, float *i, float *arg, float *mod, char op)
{
	if (op == 'p')
	{
		*arg = atan(*i / *r);
		*mod = *r / cos(*arg);
		*arg = deg(*arg);
	}
	else if (op == 'c')
	{
		*r = *mod * cosf(rad(*arg));
		*i = *mod * sinf(rad(*arg));
	}
}
