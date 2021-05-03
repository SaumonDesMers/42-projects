#include "include_lib.h"

void	get_data_img(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int		valid_coord(t_vector3 coord, t_root *root)
{
	return (coord.x > 0 && coord.x < root->win.widht && coord.y > 0 && coord.y < root->win.height);
}

int	update_img(t_root *root)
{
	(void)root;
	rendering(root);
	mlx_put_image_to_window(root->mlx, root->win.win, root->cam.img.img, 0, 0);
	return (0);
}

void	create_img(t_root *root)
{
	root->cam.img.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->cam.img.img == NULL)
		exit(0);
	get_data_img(&root->cam.img);

	root->cam.img_grid.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->cam.img_grid.img == NULL)
		exit(0);
	get_data_img(&root->cam.img_grid);
}