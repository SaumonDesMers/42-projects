#include "includes.h"

int		mouse_hook(int	button, int x, int y, t_root *root)
{
	float		fx;
	float		fy;

	(void)button;
	fx = (float)x;
	fy = (float)y;
	if (button == 1)
	{
		set_c(&root->grid.c, (fx / root->win.widht * root->grid.scale.x * 2) - 2, 2 - (fy / root->win.height * root->grid.scale.y * 2));
		julia(root->grid.c, root);
	}
	else if (button == 4)// zoom
	{
		root->grid.scale.x /= 2;
		root->grid.scale.y /= 2;
		julia(root->grid.c, root);
	}
	else if (button == 5)// dezoom
	{
		root->grid.scale.x *= 2;
		root->grid.scale.y *= 2;
		julia(root->grid.c, root);
	}
	printf("%d\n", button);
	return (0);
}