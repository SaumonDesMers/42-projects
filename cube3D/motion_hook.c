#include "include_lib.h"

int		motion_hook(int x, int y, t_root *root)
{
	move_view(x, y, root);
	return (0);
}