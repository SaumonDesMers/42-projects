#include "includes.h"

int	julia_serie(t_complexe c)
{
	t_complexe	z;
	t_complexe	tmp;
	float		mod;
	int			i;
	
	i = 0;
	while (i < 10)
	{
		mult_c(&tmp, z, z);
		add_c(&z, tmp, c);
		i++;
	}
	mod = sqrt((z.r * z.r) + (z.i * z.i));
	return (mod);
}

int	julia(t_root *root)
{
	t_vector2	pxl;
	t_complexe	z;
	t_complexe	c;
	float		i;

	if (!create_img(&root->grid.img, root->win.widht, root->win.height, root))
		return (0);

	root->grid.scale.x = 2;
	root->grid.scale.y = 2;

	set_c(&z, -root->grid.scale.x, root->grid.scale.y);
	set_c(&c, -0.75, 0);
	pxl.x = 0;
	pxl.y = 0;

	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		z.i = root->grid.scale.y;
		while (pxl.y < root->win.height)
		{
			i = julia_serie(c);
			i = i / 10 * 255;
			pixel_put(&root->grid.img, pxl, create_trgb(0,(int)i,(int)i,(int)i));
			pxl.y++;
			z.i -= root->grid.scale.y / 500;
		}
		pxl.x++;
		z.r += root->grid.scale.x / 500;
	}
	printf("%.3f %.3f\n", z.r, z.i);
	mlx_put_image_to_window(root->mlx, root->win.win, root->grid.img.img, 0, 0);
	return (1);
}