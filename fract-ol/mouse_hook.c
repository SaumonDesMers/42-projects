#include "includes.h"

int	mouse_hook(int button, int x, int y, t_root *root)
{
	float	fx;
	float	fy;

	fx = (float)x;
	fy = (float)y;
	root->grid.pos_cam.x = ((fx / root->win.widht * root->grid.scale * 2)
			- root->grid.scale) + root->grid.pos_cam.x;
	root->grid.pos_cam.y = (root->grid.scale - (fy / root->win.height
				* root->grid.scale * 2)) + root->grid.pos_cam.y;
	if (button == 4)
		root->grid.scale /= 1.5;
	else if (button == 5)
		root->grid.scale *= 1.5;
	update_img(root);
	return (0);
}
