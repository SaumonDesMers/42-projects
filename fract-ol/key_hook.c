#include "includes.h"

int	key_hook(int keycode, t_root *root)
{
	(void)root;
	if (keycode == 65307)
	{
		mlx_destroy_window(root->mlx, root->win.win);
		mlx_destroy_display(root->mlx);
		exit(0);
	}
	else if (keycode == 65361)
		root->grid.pos_cam.x -= root->grid.scale / 10;
	else if (keycode == 65362)
		root->grid.pos_cam.y += root->grid.scale / 10;
	else if (keycode == 65363)
		root->grid.pos_cam.x += root->grid.scale / 10;
	else if (keycode == 65364)
		root->grid.pos_cam.y -= root->grid.scale / 10;
	else if (keycode == 99)
	{
		root->grid.color++;
		if (root->grid.color > 3)
			root->grid.color = 0;
	}
	update_img(root);
	return (0);
}
