#include "includes.h"

int	julia_serie(t_complexe z, t_complexe c)
{
	t_complexe	tmp;
	float		starting_mod;
	float		mod[2];
	int			i;
	
	starting_mod = sqrt((z.r * z.r) + (z.i * z.i));
	if (starting_mod > 2)
		return (0);
	i = 0;
	while (i < 255)
	{
		mult_c(&tmp, z, z);
		add_c(&z, tmp, c);
		mod[0] = sqrt((z.r * z.r) + (z.i * z.i));
		mod[1] = z.r / cos(atan(z.i / z.r));
		if (mod[0] > 1 && mod [0] > 1)
			return (i);
		i++;
	}
	// if (mod[1] < starting_mod)
	// 	return (-1);
	return (-1);
}

int	julia(t_complexe c, t_root *root)
{
	t_vector2	pxl;
	t_complexe	z;
	float		i;

	if (!create_img(&root->grid.img, root->win.widht, root->win.height, root))
		return (0);

	set_c(&z, -root->grid.scale.x, root->grid.scale.y);
	pxl.x = 0;
	pxl.y = 0;

	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		z.i = root->grid.scale.y;
		while (pxl.y < root->win.height)
		{
			i = julia_serie(z, c);
			if (i == -1)
				pixel_put(&root->grid.img, pxl, create_trgb(0,255,255,255));
			else
				pixel_put(&root->grid.img, pxl, create_trgb(0,i,i,i));
			pxl.y++;
			z.i -= root->grid.scale.y / root->win.height * 2;
		}
		pxl.x++;
		z.r += root->grid.scale.x / root->win.widht * 2;
	}
	printf("%.3f %.3f\n", c.r, c.i);
	mlx_put_image_to_window(root->mlx, root->win.win, root->grid.img.img, 0, 0);
	return (1);
}