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

void	error_catch(t_bool signal)
{
	if (signal < 0)
	{
		if (signal == ERROR)
			printf("Error\n");
		else if (signal == ERROR_FILE)
			printf("Error file\n");
		else if (signal == ERROR_MALLOC)
			printf("Error malloc\n");
		exit(0);
	}
}

int	update_img(t_root *root)
{
	
	mlx_put_image_to_window(root->mlx, root->win.win, root->img.img, 0, 0);
	return (1);
}
