#include "include_lib.h"

int detect_colision(t_vector3 coord, t_root *root)
{
	return (root->input.grid[(int)trunc(coord.x)][(int)trunc(coord.y)] == '1');
}