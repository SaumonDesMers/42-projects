#include "include_lib.h"

float	cast_ray_DDA(float angle, t_vector3 *point, t_root *root)
{
	t_vector3	dir;
	t_vector3	step;
	t_vector3	delta;
	t_vector3	len;
	int			cell[2];

	// initialize
	dir.x = cos(rad(angle)); // angle par rapport a l'horizontal
	dir.y = sin(rad(angle));

	delta.x = 0;
	delta.y = 0;
	if (dir.x)
		delta.x = fabs(1 / dir.x);
	if (dir.y)
		delta.y = fabs(1 / dir.y);

	point->x = root->cam.pos.x;
	point->y = root->cam.pos.y;

	cell[0] = (int)trunc(point->x);
	cell[1] = (int)trunc(point->y);

	step.x = 1;
	step.y = 1;
	if (dir.x < 0)
		step.x = -1;
	if (dir.y < 0)
		step.y = -1;

	// first step
	len.x = delta.x;
	if (point->x != trunc(point->x))
		len.x = delta.x - ((1 - point->x + trunc(point->x)) / cos(rad(angle)));
	len.y = delta.y;
	if (point->y != trunc(point->y))
		len.y = delta.y - ((1 - point->y + trunc(point->y)) / sin(rad(angle)));

	len.x = fabs(len.x);
	len.y = fabs(len.y);
	// loop
	while (root->input.grid[cell[0]][cell[1]] == '0')
	{
		if (len.x <= len.y)
		{
			cell[0] += step.x;
			point->x = root->cam.pos.x + len.x * cos(rad(angle));
			point->y = root->cam.pos.y + len.x * sin(rad(angle));
			len.x += delta.x;
		}
		if (len.x > len.y)
		{
			cell[1] += step.y;
			point->x = root->cam.pos.x + len.y * cos(rad(angle));
			point->y = root->cam.pos.y + len.y * sin(rad(angle));
			len.y += delta.y;
		}
	}
	if (len.x < len.y)
		return (len.x);
	if (len.x > len.y)
		return (len.y);
	return (len.x);
}