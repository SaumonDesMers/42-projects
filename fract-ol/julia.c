#include "includes.h"

int	julia_serie(t_complexe z, t_complexe c)
{
	t_complexe	tmp;
	float		starting_mod;
	float		mod;
	int			i;

	starting_mod = sqrt((z.r * z.r) + (z.i * z.i));
	if (starting_mod > 2)
		return (0);
	i = 0;
	while (i < 200)
	{
		mult_c(&tmp, z, z);
		add_c(&z, tmp, c);
		mod = sqrt((z.r * z.r) + (z.i * z.i));
		// mod = z.r / cos(atan(z.i / z.r));
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

	if (!create_img(&root->grid.img, root->win.widht, root->win.height, root))
		return (0);

	set_c(&z, root->grid.pos_cam.x - root->grid.scale, root->grid.pos_cam.y + root->grid.scale);
	pxl.x = 0;
	pxl.y = 0;

	while (pxl.x < root->win.widht)
	{
		pxl.y = 0;
		z.i = root->grid.scale;
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
	mlx_put_image_to_window(root->mlx, root->win.win, root->grid.img.img, 0, 0);
	// mlx_destroy_image(root->mlx, &root->grid.img);
	return (1);
}

void	fractal_color(int n, t_vector2 pxl, t_root *root)
{
	int	color;

	if (n == -1)
		color = create_trgb(0, 255, 255, 255);
	else
	{
		if (n % 10 == 0)
			color = create_trgb(0, n, n, 50);
		else if (n % 10 == 1)
			color = create_trgb(0, n, n, 100);
		else if (n % 10 == 2)
			color = create_trgb(0, n, n, 150);
		else if (n % 10 == 3)
			color = create_trgb(0, n, n, 200);
		else if (n % 10 == 4)
			color = create_trgb(0, n, n, 250);
		else if (n % 10 == 5)
			color = create_trgb(0, n, n, 250);
		else if (n % 10 == 6)
			color = create_trgb(0, n, n, 200);
		else if (n % 10 == 7)
			color = create_trgb(0, n, n, 150);
		else if (n % 10 == 8)
			color = create_trgb(0, n, n, 100);
		else if (n % 10 == 9)
			color = create_trgb(0, n, n, 50);
	}
	pixel_put(&root->grid.img, pxl, color);
}
