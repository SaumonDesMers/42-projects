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
	
	root->img.grid.widht = 500;
	root->img.grid.height = 500;
	root->img.grid.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->img.grid.img == NULL)
		exit(0);
	get_data_img(&root->img.grid);

	root->img.test.widht = root->win.widht;
	root->img.test.height = root->win.height;
	root->img.test.img = mlx_new_image(root->mlx, root->win.widht, root->win.height);
	if (root->img.test.img == NULL)
		exit(0);
	get_data_img(&root->img.test);
}

void	import_img(t_img *img, char *path_name, t_root *root)
{
	img->img = mlx_xpm_file_to_image(root->mlx, path_name, &img->widht, &img->height);
	if (img->img == NULL)
		exit(0);
	get_data_img(img);
}