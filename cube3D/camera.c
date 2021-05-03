#include "include_lib.h"

int		move_view(int x, int y, t_root *root)
{
	t_vector3	view_move;

	view_move.x = -x + root->win.widht / 2;
	view_move.z = -y + root->win.height / 2;

	root->cam.view_angle.x += normalized(view_move.x);
	if (root->cam.view_angle.x < 0)
		root->cam.view_angle.x += 360;
	if (root->cam.view_angle.x > 360)
		root->cam.view_angle.x -= 360;

	root->cam.view_angle.z += normalized(view_move.z);
	if (root->cam.view_angle.z < -90)
		root->cam.view_angle.z = -90;
	if (root->cam.view_angle.z > 90)
		root->cam.view_angle.z = 90;

	//if (view_move.x != 0 || view_move.z != 0)
	//	printf("%f : %f\n", root->cam.view_angle.x, root->cam.view_angle.z);
	mlx_mouse_move(root->mlx, root->win.win, root->win.widht / 2, root->win.height / 2);
	return (0);
}

void	mouve_cam_from_view(int dir, t_root *root)
{
	//int	x;

	root->cam.pos.x += 0.1 * dir * cos(rad(root->cam.view_angle.x));
	root->cam.pos.y += 0.1 * dir * sin(rad(root->cam.view_angle.x));
	//x = trunc(root->cam.view_angle.x);
	//printf("view : %d\tpos : %f %f\n", x, trunc(root->cam.pos.x), trunc(root->cam.pos.y));
}