#include "include_lib.h"

void	render_floor_ceilling(t_root *root)
{
	t_vector3	pos1;
	t_vector3	pos2;

	pos1.x = 0;
	pos1.y = 0;
	pos2.x = root->win.widht;
	pos2.y = root->cam.horizon;
	draw_square(&root->img.maze, pos1, pos2, root->input.c_color);
	pos1.x = 0;
	pos1.y = root->cam.horizon;
	pos2.x = root->win.widht;
	pos2.y = root->win.height;
	draw_square(&root->img.maze, pos1, pos2, root->input.f_color);
}

void	manipulate_img(t_root *root)
{
	t_vector3	scale;
	t_vector3	rotation;

	scale.x = 1;
	scale.y = 1;
	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;
	(void)root;
	print_img(&root->img.test, &root->img.NO, scale, rotation, root);
}

void	rendering(t_root *root)
{
	(void)root;
	// root->cam.horizon = root->win.height / 2 + (root->cam.view_angle.y * 10);
	root->cam.horizon = root->win.height / 2;
	render_floor_ceilling(root);
	print_grid(root);
	ray_casting_dda(root);
	// manipulate_img(root);
}

int	update_img(t_root *root)
{
	(void)root;
	rendering(root);
	mlx_put_image_to_window(root->mlx, root->win.win, root->img.maze.img, 0, 0);
	// mlx_put_image_to_window(root->mlx, root->win.win, root->img.grid.img, 0, 0);
	// mlx_put_image_to_window(root->mlx, root->win.win, root->img.test.img, 0, 0);
	return (0);
}