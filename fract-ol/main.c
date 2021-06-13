#include "includes.h"

void	init(t_root *root)
{
	root->win.widht = 1000;
	root->win.height = 1000;

	root->grid.pos_cam.x = 0;
	root->grid.pos_cam.y = 0;

	root->grid.pos_mouse.x = 0;
	root->grid.pos_mouse.y = 0;

	root->grid.scale = 2;
}

int	main(int ac, char **av)
{
	t_root		root;

	init(&root);
	if (ac != 2)
		return (0);
	if (av[1][0] != 'm' && av[1][0] != 'j')
		return (0);
	root.set = av[1][0];

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "fract-ol");

	mlx_hook(root.win.win, 2, 1L << 0, key_hook, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);
	// mlx_loop_hook(root.mlx, update_img, &root);

	set_c(&root.grid.c, 0.285, 0.013);
	if (root.set == 'j')
		julia(root.grid.c, &root);
	else if (root.set == 'm')
		mandelbrot(&root);

	mlx_loop(root.mlx);

	return (0);
}
