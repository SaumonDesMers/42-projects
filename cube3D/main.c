#include "include_lib.h"

void init(t_root *root)
{
	root->cam.view_angle.x = 0; // 0 = EAST
	root->cam.view_angle.y = 0;
	root->cam.pos.x = 5.5;
	root->cam.pos.y = 2;
	root->cam.vision.x = 60;
}

int	main(void)
{
	t_root		root;

	root.mlx = mlx_init();
	read_file("./file.txt", &root);
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "salut");
	
	init(&root);

	create_img(&root);

	//mlx_mouse_hide(root.mlx.mlx, root.mlx.win);
	mlx_do_key_autorepeaton(root.mlx);

	mlx_hook(root.win.win, 2, 1L<<0, key_hook, &root);
	mlx_loop_hook(root.mlx, update_img, &root);
	mlx_hook(root.win.win, 6, 1L<<6, motion_hook, &root);

	mlx_loop(root.mlx);

	return (0);
}