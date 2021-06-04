#include "include_lib.h"

int		move_view(int x, int y, t_root *root)
{
	t_vector3	view_move;

	view_move.x = x - root->win.widht / 2;
	view_move.y = -y + root->win.height / 2;

	root->cam.view_angle.x += 0.2 * normalized(view_move.x);
	if (root->cam.view_angle.x < 0)
		root->cam.view_angle.x += 360;
	if (root->cam.view_angle.x > 360)
		root->cam.view_angle.x -= 360;

	root->cam.view_angle.y += 0.2 * normalized(view_move.y);
	if (root->cam.view_angle.y < -90)
		root->cam.view_angle.y = -90;
	if (root->cam.view_angle.y > 90)
		root->cam.view_angle.y = 90;
	mlx_mouse_move(root->mlx, root->win.win, root->win.widht / 2, root->win.height / 2);
	return (0);
}

void	mouve_cam_from_view(int v_angle, t_root *root)
{
	t_vector3	coord;
	int			h_angle;

	h_angle = root->cam.view_angle.x - v_angle;
	coord.x = root->cam.pos.x;
	coord.y = root->cam.pos.y;
	coord.x += 0.05 * cos(rad(h_angle));
	coord.y += 0.05 * sin(rad(h_angle));
	if (detect_colision(coord, root))
		return ;
	root->cam.pos.x = coord.x;
	root->cam.pos.y = coord.y;
}