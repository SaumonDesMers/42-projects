#include "includes.h"

int	mandelbrot_serie(t_complexe z, t_complexe c)
{
	t_complexe	tmp;
	float		mod;
	int			i;

	i = 0;
	while (i < 200)
	{
		mult_c(&tmp, z, z);
		add_c(&z, tmp, c);
		mod = sqrt((z.r * z.r) + (z.i * z.i));
		if (mod > 2)
			return (i);
		i++;
	}
	return (-1);
}

int	mandelbrot(t_root *root)
{
	t_vector2	pxl;
	t_complexe	z;
	t_complexe	c;
	float		i;

	set_c(&c, root->grid.pos_cam.x - root->grid.scale,
		root->grid.pos_cam.y + root->grid.scale);
	set_c(&z, 0, 0);
	pxl.x = 0;
	pxl.y = 0;
	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		c.i = root->grid.pos_cam.y + root->grid.scale;
		while (pxl.y < root->win.height)
		{
			i = julia_serie(z, c);
			fractal_color(i, pxl, root);
			pxl.y++;
			c.i -= root->grid.scale / root->win.height * 2;
		}
		pxl.x++;
		c.r += root->grid.scale / root->win.widht * 2;
	}
	return (1);
}
