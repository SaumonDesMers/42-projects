#include "include_lib.h"

void	get_data_img(t_img *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	create_img(t_root *root)
{
	root->img.maze.widht = root->win.widht;
	root->img.maze.height = root->win.height;
	root->img.maze.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->img.maze.img == NULL)
		exit(0);
	get_data_img(&root->img.maze);
	
	root->img.grid.widht = root->win.widht;
	root->img.grid.height = root->win.height;
	root->img.grid.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->img.grid.img == NULL)
		exit(0);
	get_data_img(&root->img.grid);
}