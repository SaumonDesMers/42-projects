#include "includes.h"

int	key_hook(int keycode, t_root *root)
{
	(void)root;
	if (keycode == 65307)
	{
		//mlx_destroy_image(root->mlx, root->win.img);
		mlx_destroy_window(root->mlx, root->win.win);
		mlx_destroy_display(root->mlx);
		//mlx_loop_end(root->mlx);
		exit(0);
	}
	//printf("%d\n", keycode);
	return (0);
}
