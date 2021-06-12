#include "includes.h"

void	init(t_root *root)
{
	root->win.widht = 1000;
	root->win.height = 1000;

	root->grid.pos_cam.x = 0;
	root->grid.pos_cam.y = 0;

	root->grid.pos_mouse.x = 0;
	root->grid.pos_mouse.y = 0;

	root->grid.scale.x = 2;
	root->grid.scale.y = 2;
}

int	main(void)
{
	t_root		root;

	init(&root);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "fract-ol");

	// mlx_do_key_autorepeaton(root.mlx);

	mlx_hook(root.win.win, 2, 1L<<0, key_hook, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);
	// mlx_loop_hook(root.mlx, update_img, &root);
	// mlx_hook(root.win.win, 6, 1L<<6, motion_hook, &root);

	set_c(&root.grid.c, 0.285, 0.013);
	julia(root.grid.c, &root);

	mlx_loop(root.mlx);

	return (0);
}