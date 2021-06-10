#include "includes.h"

void	set_c(t_complexe *c, float r, float i)
{
	c->r = r;
	c->i = i;
}

void	add_c(t_complexe *rst, t_complexe c1, t_complexe c2)
{
	rst->r = c1.r + c2.r;
	rst->i = c1.i + c2.i;
}

void	mult_c(t_complexe *rst, t_complexe c1, t_complexe c2)
{
	rst->r = c1.r * c2.r - c1.i * c2.i;
	rst->i = c1.r * c2.i + c1.i * c2.r;
}
