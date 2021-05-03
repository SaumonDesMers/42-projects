#include "include_lib.h"

int	click(int button, int x, int y, t_root *root)
{
	(void)button;
	t_vector3	coord;

	coord.x = x;
	coord.y = y;
	pixel_put(coord, create_trgb(0, 255, 255, 255), root);
	//mlx_clear_window(root->mlx, root->mlx.win);
	//mlx_put_image_to_window(root->mlx.mlx, root->mlx.win, root->img.img, x, y);
	return (0);
}

void init(t_root *root)
{
	root->cam.view_angle.x = 0;
	root->cam.view_angle.z = 0;
	root->cam.pos.x = 0;
	root->cam.pos.y = 0;
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

	rendering(&root);

	//mlx_mouse_hide(root.mlx.mlx, root.mlx.win);
	mlx_do_key_autorepeaton(root.mlx);
	
	mlx_mouse_hook(root.win.win, click, &root);
	mlx_hook(root.win.win, 2, 1L<<0, key_hook, &root);
	mlx_loop_hook(root.mlx, update_img, &root);
	mlx_hook(root.win.win, 6, 1L<<6, move_view, &root);

	mlx_loop(root.mlx);

	return (0);
}