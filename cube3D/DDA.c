#include "include_lib.h"

float	cast_ray_DDA(float h_angle, t_vector3 *point, t_root *root)
{
	t_vector3	dir;
	t_vector3	step;
	t_vector3	delta;
	t_vector3	len;
	int			cell[2];
	t_vector3	origin;
	float		cell_size;

	cell_size = 100;
	origin.x = 100 + root->cam.pos.x * cell_size;
	origin.y = 100 + root->cam.pos.y * cell_size;

	// initialize
	dir.x = cos(rad(h_angle)); // angle par rapport a l'horizontal
	dir.y = sin(rad(h_angle));

	delta.x = 0;
	delta.y = 0;
	if (dir.x)
		delta.x = 1 / dir.x;
	if (dir.y)
		delta.y = 1 / dir.y;

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
	if (point->x != trunc(point->x) && dir.x > 0)
		len.x = delta.x - ((point->x - trunc(point->x)) / cos(rad(h_angle)));
	if (point->x != trunc(point->x) && dir.x < 0)
		len.x = delta.x - ((1 - (point->x - trunc(point->x))) / cos(rad(h_angle)));
	len.y = delta.y;
	if (point->y != trunc(point->y) && dir.y > 0)
		len.y = delta.y - ((point->y - trunc(point->y)) / sin(rad(h_angle)));
	if (point->y != trunc(point->y) && dir.y < 0)
		len.y = delta.y - ((1 - (point->y - trunc(point->y))) / sin(rad(h_angle)));

	len.x = fabs(len.x);
	len.y = fabs(len.y);
	delta.x = fabs(delta.x);
	delta.y = fabs(delta.y);

	if (len.x < 10000)
		draw_ligne(&root->cam.img_grid, origin, h_angle + 1, len.x * cell_size, 0x00ff0000);
	if (len.y < 10000)
		draw_ligne(&root->cam.img_grid, origin, h_angle - 1, len.y * cell_size, 0x00ffff00);

	// loop
	while (root->input.grid[cell[0]][cell[1]] == '0')
	{
		if (len.x <= len.y)
		{
			cell[0] += step.x;
			point->x = root->cam.pos.x + len.x * cos(rad(h_angle));
			point->y = root->cam.pos.y + len.x * sin(rad(h_angle));
			if (root->input.grid[cell[0]][cell[1]] == '0')
				len.x += delta.x;
		}
		if (len.x > len.y)
		{
			cell[1] += step.y;
			point->x = root->cam.pos.x + len.y * cos(rad(h_angle));
			point->y = root->cam.pos.y + len.y * sin(rad(h_angle));
			if (root->input.grid[cell[0]][cell[1]] == '0')
				len.y += delta.y;
		}
	}

	if (len.x < len.y)
		return (len.x);
	if (len.x > len.y)
		return (len.y);
	return (len.x);
}

void	ray_casting_DDA(t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	float		v_angle; // angle avec l'angle de vue
	t_vector3	point;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	nb_ray = root->win.widht;
	ray = 0;
	vision = 60;
	while (ray < nb_ray + 1)
	{
		v_angle = (ray / nb_ray * vision) - vision / 2;
		h_angle = root->cam.view_angle.x - v_angle;

		len = cast_ray_DDA(h_angle, &point, root);
		//printf("angle : %.2f\t len : %.2f\n", h_angle, len);
		if (len != 0)
			draw_col(&root->cam.img, ray, height(len, root), 0xffffffff, root);
		ray++;
	}
}

void	ray_casting_grid_DDA(t_vector3 origin, float cell_size, t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	float		v_angle; // angle avec l'angle de vue
	t_vector3	point;
	t_vector3	cam;

	(void)len;
	(void)h_angle;
	(void)cam;
	point.x = 0;
	point.y = 0;
	point.z = 0;
	nb_ray = 20;
	ray = 0;
	vision = 60;
	cam.x = origin.x + root->cam.pos.x * cell_size;
	cam.y = origin.y + root->cam.pos.y * cell_size;
	while (ray < nb_ray + 1)
	{
		v_angle = (ray / nb_ray * vision) - vision / 2;
		h_angle = root->cam.view_angle.x - v_angle;

		len = cast_ray_DDA(h_angle, &point, root);
		point.x = point.x * cell_size + origin.x;
		point.y = point.y * cell_size + origin.y;
		draw_disk(&root->cam.img_grid, point, 3, 0x00ffff00);
		//draw_ligne(&root->cam.img_grid, cam, h_angle, len * cell_size, 0xffffffff);
		ray++;
	}
}