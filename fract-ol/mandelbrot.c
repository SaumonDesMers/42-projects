#include "includes.h"

int	mandelbrot_serie(t_complexe z, t_complexe c)
{
	t_complexe	tmp;
	float		starting_mod;
	float		mod;
	int			i;

	starting_mod = sqrt((z.r * z.r) + (z.i * z.i));
	if (starting_mod > 2)
		return (0);
	i = 0;
	while (i < 255)
	{
		mult_c(&tmp, z, z);
		add_c(&z, tmp, c);
		// mod = sqrt((z.r * z.r) + (z.i * z.i));
		mod = z.r / cos(atan(z.i / z.r));
		if (mod > 1)
			return (i);
		i++;
	}
	// if (mod < starting_mod)
	// 	return (-1);
	return (-1);
}

int	mandelbrot(t_root *root)
{
	t_vector2	pxl;
	t_complexe	z;
	t_complexe	c;
	float		i;

	if (!create_img(&root->grid.img, root->win.widht, root->win.height, root))
		return (0);

	set_c(&c, -root->grid.scale, root->grid.scale);
	set_c(&z, 0, 0);
	pxl.x = 0;
	pxl.y = 0;

	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		c.i = root->grid.scale;
		while (pxl.y < root->win.height)
		{
			i = julia_serie(z, c);
			if (i == -1)
				pixel_put(&root->grid.img, pxl, create_trgb(0, 255, 255, 255));
			else
				pixel_put(&root->grid.img, pxl, create_trgb(0, i, i, i));
			pxl.y++;
			c.i -= root->grid.scale / root->win.height * 2;
		}
		pxl.x++;
		c.r += root->grid.scale / root->win.widht * 2;
	}
	printf("%.3f %.3f\n", c.r, c.i);
	mlx_put_image_to_window(root->mlx, root->win.win, root->grid.img.img, 0, 0);
	return (1);
}
