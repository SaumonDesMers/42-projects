#include "includes.h"

int	mouse_hook(int	button, int x, int y, t_root *root)
{
	float		fx;
	float		fy;

	fx = (float)x;
	fy = (float)y;
	root->grid.pos_cam.x = ((fx / root->win.widht * root->grid.scale * 2) - root->grid.scale) + root->grid.pos_cam.x;
	root->grid.pos_cam.y = (root->grid.scale - (fy / root->win.height * root->grid.scale * 2)) + root->grid.pos_cam.y;
	printf("%.3f %.3f\n", root->grid.pos_cam.x, root->grid.pos_cam.y);
	// if (button == 1 && root->set == 'j')
	// 	set_c(&root->grid.c, (fx / root->win.widht * root->grid.scale * 2) - root->grid.scale, root->grid.scale - (fy / root->win.height * root->grid.scale * 2));
	if (button == 4) // zoom
		root->grid.scale /= 1.5;
	else if (button == 5) // dezoom
		root->grid.scale *= 1.5;
	if (root->set == 'j')
		julia(root->grid.c, root);
	else if (root->set == 'm')
		mandelbrot(root);
	printf("%d\n", button);
	return (0);
}
