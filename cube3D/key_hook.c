#include "include_lib.h"

int	key_hook(int keycode, t_root *root)
{
	(void)root;
	if (keycode == 65307)
	{
		//mlx_destroy_image(root->mlx, root->win.img);
		mlx_destroy_window(root->mlx, root->win.win);
		mlx_destroy_display(root->mlx);
		free_grid(root);
		//mlx_loop_end(root->mlx);
		exit(0);
	}
	if (keycode == 65363)
		move_view(root->win.widht / 2 + 1, root->win.height / 2, root);
	if (keycode == 65361)
		move_view(root->win.widht / 2 - 1, root->win.height / 2, root);
	if (keycode == 119)
		mouve_cam_from_view(0, root);
	if (keycode == 115)
		mouve_cam_from_view(180, root);
	if (keycode == 100)
		mouve_cam_from_view(270, root);
	if (keycode == 97)
		mouve_cam_from_view(90, root);
	//printf("%d\n", keycode);
	return (0);
}