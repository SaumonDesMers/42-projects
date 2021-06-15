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
	root->grid.color = 0;
}

int	main(int ac, char **av)
{
	t_root		root;

	init(&root);
	if (!input(ac, av, &root))
		return (0);
	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht,
			root.win.height, "fract-ol");
	mlx_hook(root.win.win, 2, 1L << 0, key_hook, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);
	if (!create_img(&root.grid.img, root.win.widht, root.win.height, &root))
		return (0);
	update_img(&root);
	mlx_loop(root.mlx);
	return (0);
}
