#include "includes.h"

void	init(t_root *root)
{
	root->win.widht = 1000;
	root->win.height = 1000;

	root->grid.grid_size = (t_vector3) {.x = 0, .y = 0};
}

int	main(int ac, char **av)
{
	t_root		root;
	int			signal;

	(void)ac;
	(void)av;
	if (ac != 2)
		error_catch(ERROR_FILE);
	init(&root);
	signal = open_file(av[1], &root);
	error_catch(signal);

	root.mlx = mlx_init();
	root.win.win = mlx_new_window(root.mlx, root.win.widht, root.win.height, "fdf");

	mlx_hook(root.win.win, 2, 1L << 0, key_hook, &root);
	mlx_mouse_hook(root.win.win, mouse_hook, &root);

	mlx_loop(root.mlx);
	return (0);
}