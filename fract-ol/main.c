#include "includes.h"

void	init(t_root *root)
{
	root->win.widht = 1000;
	root->win.height = 1000;

	root->grid.pos_cam.x = 0;
	root->grid.pos_cam.x = 0;
}

int	main(void)
{
	t_root		root;
	t_complexe	c;

	init(&root);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "fract-ol");

	// mlx_do_key_autorepeaton(root.mlx);

	mlx_hook(root.win.win, 2, 1L<<0, key_hook, &root);
	// mlx_loop_hook(root.mlx, update_img, &root);
	// mlx_hook(root.win.win, 6, 1L<<6, motion_hook, &root);

	set_c(&c, 0, 0);
	julia(&root);

	mlx_loop(root.mlx);

	return (0);
}