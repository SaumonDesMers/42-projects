#include "includes.h"

int	julia_serie(t_complexe z, t_complexe c)
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

int	julia(t_complexe c, t_root *root)
{
	t_vector2	pxl;
	t_complexe	z;
	float		i;

	set_c(&z, root->grid.pos_cam.x - root->grid.scale,
		root->grid.pos_cam.y + root->grid.scale);
	pxl.x = 0;
	pxl.y = 0;
	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		z.i = root->grid.pos_cam.y + root->grid.scale;
		while (pxl.y < root->win.height)
		{
			i = julia_serie(z, c);
			fractal_color(i, pxl, root);
			pxl.y++;
			z.i -= root->grid.scale / root->win.height * 2;
		}
		pxl.x++;
		z.r += root->grid.scale / root->win.widht * 2;
	}
	return (1);
}

void	fractal_color(int n, t_vector2 pxl, t_root *root)
{
	int	color;

	if (n == -1)
		color = create_trgb(0, 255, 255, 255);
	else if (root->grid.color == 0)
		color = create_trgb(0, n % 17 * 16, n % 20 * 10, n % 11 * 25);
	else if (root->grid.color == 1)
		color = create_trgb(0, n % 9 * 25, n % 20 * 9, n % 17 * 15);
	else if (root->grid.color == 2)
		color = create_trgb(0, n % 19 * 10, n % 11 * 25, n % 17 * 15);
	else if (root->grid.color == 3)
		color = create_trgb(0, n % 20 * 10, n % 17 * 15, n % 10 * 25);
	pixel_put(&root->grid.img, pxl, color);
}
