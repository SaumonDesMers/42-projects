#include "includes.h"

void	get_data_img(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

int	create_img(t_img *img, float widht, float height, t_root *root)
{
	img->widht = widht;
	img->height = height;
	img->img = mlx_new_image(root->mlx, widht, height);
	if (img->img == NULL)
		exit(0);
	get_data_img(img);
	return (1);
}

int	input(int ac, char **av, t_root *root)
{
	if (ac == 2)
	{
		if (av[1][0] != 'm' && av[1][0] != 'j')
			return (0);
		root->set = av[1][0];
		set_c(&root->grid.c, -0.8, 0.156);
		return (1);
	}
	else if (ac == 4)
	{
		if (av[1][0] != 'j')
			return (0);
		root->set = av[1][0];
		set_c(&root->grid.c, ft_atof(av[2]), ft_atof(av[3]));
		return (1);
	}
	else
		printf("Option available :\nMandelbrot = m\nJulia = j\n");
	return (0);
}

int	update_img(t_root *root)
{
	if (root->set == 'j')
		julia(root->grid.c, root);
	else if (root->set == 'm')
		mandelbrot(root);
	mlx_put_image_to_window(root->mlx, root->win.win, root->grid.img.img, 0, 0);
	return (1);
}
