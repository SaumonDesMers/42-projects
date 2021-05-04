#include "include_lib.h"

void init(t_root *root)
{
	root->cam.view_angle.x = 45; // 0 = EAST
	root->cam.view_angle.z = 0;
	root->cam.pos.x = 5;
	root->cam.pos.y = 6;
	root->cam.pos.z = 0;
}

int	main(void)
{
	t_root		root;

	set_input(&root);
	init(&root);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "salut");

	create_img(&root);

	//mlx_mouse_hide(root.mlx.mlx, root.mlx.win);
	mlx_do_key_autorepeaton(root.mlx);

	//rendering(&root);
	//print_grid(&root);

	mlx_hook(root.win.win, 2, 1L<<0, key_hook, &root);
	mlx_loop_hook(root.mlx, update_img, &root);
	mlx_hook(root.win.win, 6, 1L<<6, motion_hook, &root);

	mlx_loop(root.mlx);

	return (0);
}