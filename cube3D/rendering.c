#include "include_lib.h"

void	render_floor_ceilling(t_root *root)
{
	t_vector3	pos1;
	t_vector3	pos2;

	pos1.x = 0;
	pos1.y = 0;
	pos2.x = root->win.widht;
	pos2.y = root->cam.horizon;
	draw_square(pos1, pos2, root->input.c_color, root);
	pos1.x = 0;
	pos1.y = root->cam.horizon;
	pos2.x = root->win.widht;
	pos2.y = root->win.height;
	draw_square(pos1, pos2, root->input.f_color, root);
}

void	rendering(t_root *root)
{
	(void)root;
	root->cam.horizon = root->win.height / 2;
	render_floor_ceilling(root);
	ray_casting(root);
}