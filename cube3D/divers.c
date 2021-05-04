#include "include_lib.h"

void	get_data_img(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	create_img(t_root *root)
{
	root->cam.img.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->cam.img.img == NULL)
		exit(0);
	get_data_img(&root->cam.img);
	root->cam.img.widht = root->win.widht;
	root->cam.img.height = root->win.height;

	root->cam.img_grid.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->cam.img_grid.img == NULL)
		exit(0);
	get_data_img(&root->cam.img_grid);
	root->cam.img_grid.widht = root->win.widht;
	root->cam.img_grid.height = root->win.height;
}