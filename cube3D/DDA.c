#include "include_lib.h"

void	init_DDA(float h_angle, t_DDA *var, t_root *root)
{
	var->dir.x = cos(rad(h_angle));
	var->dir.y = sin(rad(h_angle));

	var->delta.x = 0;
	var->delta.y = 0;
	if (var->dir.x)
		var->delta.x = 1 / var->dir.x;
	if (var->dir.y)
		var->delta.y = 1 / var->dir.y;

	var->point.x = root->cam.pos.x;
	var->point.y = root->cam.pos.y;

	var->cell[0] = (int)trunc(var->point.x);
	var->cell[1] = (int)trunc(var->point.y);

	var->step.x = 1;
	var->step.y = 1;
	if (var->dir.x < 0)
		var->step.x = -1;
	if (var->dir.y < 0)
		var->step.y = -1;

	var->len.x = var->delta.x;
	if (var->dir.x > 0)
		var->len.x = var->delta.x - ((var->point.x - trunc(var->point.x)) / cos(rad(h_angle)));
	if (var->dir.x < 0)
		var->len.x = var->delta.x - ((1 - (var->point.x - trunc(var->point.x))) / cos(rad(h_angle)));
	var->len.y = var->delta.y;
	if (var->dir.y > 0)
		var->len.y = var->delta.y - ((var->point.y - trunc(var->point.y)) / sin(rad(h_angle)));
	if (var->dir.y < 0)
		var->len.y = var->delta.y - ((1 - (var->point.y - trunc(var->point.y))) / sin(rad(h_angle)));

	var->len.x = fabs(var->len.x);
	var->len.y = fabs(var->len.y);
	var->delta.x = fabs(var->delta.x);
	var->delta.y = fabs(var->delta.y);
}

float	cast_ray_DDA(float h_angle, t_DDA *var, t_root *root)
{
	while (root->input.grid[var->cell[0]][var->cell[1]] == '0')
	{
		if (var->len.x <= var->len.y)
		{
			var->cell[0] += var->step.x;
			var->point.x = root->cam.pos.x + var->len.x * cos(rad(h_angle));
			var->point.y = root->cam.pos.y + var->len.x * sin(rad(h_angle));
			if (root->input.grid[var->cell[0]][var->cell[1]] == '0')
				var->len.x += var->delta.x;
		}
		if (var->len.x > var->len.y)
		{
			var->cell[1] += var->step.y;
			var->point.x = root->cam.pos.x + var->len.y * cos(rad(h_angle));
			var->point.y = root->cam.pos.y + var->len.y * sin(rad(h_angle));
			if (root->input.grid[var->cell[0]][var->cell[1]] == '0')
				var->len.y += var->delta.y;
		}
	}

	if (var->len.x < var->len.y)
		return (var->len.x);
	if (var->len.x > var->len.y)
		return (var->len.y);
	return (var->len.x);
}

void	ray_casting_DDA(t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	float		v_angle; // angle avec l'angle de vue
	t_DDA		DDA_var;

	nb_ray = root->win.widht;
	ray = 0;
	vision = 60;
	while (ray < nb_ray)
	{
		v_angle = (ray / nb_ray * vision) - vision / 2;
		h_angle = root->cam.view_angle.x - v_angle;

		init_DDA(h_angle, &DDA_var, root);
		len = cast_ray_DDA(h_angle, &DDA_var, root);
		//printf("angle : %.2f\t len : %.2f\n", h_angle, len);
		if (len != 0)
			draw_col(&root->img.maze, ray, height(len, root), 0xffffffff, root);
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
	t_DDA		DDA_var;
	t_vector3	cam;

	(void)len;
	(void)h_angle;
	(void)cam;
	nb_ray = 100;
	ray = 0;
	vision = 60;
	cam.x = origin.x + root->cam.pos.x * cell_size;
	cam.y = origin.y + root->cam.pos.y * cell_size;
	while (ray < nb_ray + 1)
	{
		v_angle = (ray / nb_ray * vision) - vision / 2;
		h_angle = root->cam.view_angle.x - v_angle;

		init_DDA(h_angle, &DDA_var, root);
		len = cast_ray_DDA(h_angle, &DDA_var, root);
		DDA_var.point.x = DDA_var.point.x * cell_size + origin.x;
		DDA_var.point.y = DDA_var.point.y * cell_size + origin.y;
		draw_disk(&root->img.grid, DDA_var.point, 3, 0x00ffff00);
		draw_ligne(&root->img.grid, cam, h_angle, len * cell_size, 0xffffffff);
		ray++;
	}
}