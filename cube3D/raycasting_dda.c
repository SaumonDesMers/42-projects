#include "include_lib.h"

void	init_ray(t_ray *var, t_root *root)
{
	var->dir.x = cos(rad(var->h_angle));
	var->dir.y = sin(rad(var->h_angle));

	var->delta.x = INFINITY;
	var->delta.y = INFINITY;
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
		var->len.x = var->delta.x - ((var->point.x - trunc(var->point.x)) / cos(rad(var->h_angle)));
	if (var->dir.x < 0)
		var->len.x = var->delta.x - ((1 - (var->point.x - trunc(var->point.x))) / cos(rad(var->h_angle)));
	var->len.y = var->delta.y;
	if (var->dir.y > 0)
		var->len.y = var->delta.y - ((var->point.y - trunc(var->point.y)) / sin(rad(var->h_angle)));
	if (var->dir.y < 0)
		var->len.y = var->delta.y - ((1 - (var->point.y - trunc(var->point.y))) / sin(rad(var->h_angle)));

	var->len.x = fabs(var->len.x);
	var->len.y = fabs(var->len.y);
	var->delta.x = fabs(var->delta.x);
	var->delta.y = fabs(var->delta.y);
}

float	cast_ray_dda(t_ray *var, t_root *root)
{
	while (root->input.grid[var->cell[0]][var->cell[1]] != '1')
	{
		if (var->len.x <= var->len.y)
		{
			var->cell[0] += var->step.x;
			var->point.x = root->cam.pos.x + var->len.x * cos(rad(var->h_angle));
			var->point.y = root->cam.pos.y + var->len.x * sin(rad(var->h_angle));
			if (root->input.grid[var->cell[0]][var->cell[1]] != '1')
				var->len.x += var->delta.x;
		}
		if (var->len.x > var->len.y)
		{
			var->cell[1] += var->step.y;
			var->point.x = root->cam.pos.x + var->len.y * cos(rad(var->h_angle));
			var->point.y = root->cam.pos.y + var->len.y * sin(rad(var->h_angle));
			if (root->input.grid[var->cell[0]][var->cell[1]] != '1')
				var->len.y += var->delta.y;
		}
	}

	if (var->len.x < var->len.y)
		return (var->len.x);
	if (var->len.x > var->len.y)
		return (var->len.y);
	return (var->len.x);
}

float	height(float distance, t_root *root)
{
	float	height;

	height = (root->win.height) / distance;
	return (height);
}

void	ray_casting_dda(t_root *root)
{
	int			nb_ray;
	float		ray;
	float		len;
	t_ray		ray_var;
	int			*color;

	nb_ray = root->win.widht;
	ray = 0;
	while (ray < nb_ray)
	{
		ray_var.h_angle = root->cam.view_angle.x + (root->cam.vision.x * (ray / nb_ray - 0.5));
		init_ray(&ray_var, root);
		len = cast_ray_dda(&ray_var, root);
		len = height(len, root);
		color = wall_texture(ray_var, len, root);
		draw_col_img(&root->img.maze, ray, len, color, root);
		free(color);
		ray++;
	}
}

void	ray_casting_grid_dda(t_vector3 origin, float cell_size, t_root *root)
{
	int			nb_ray;
	float		ray;
	float		len;
	t_ray		ray_var;
	t_vector3	cam;

	ray = 0;
	nb_ray = root->cam.vision.x;
	cam.x = origin.x + root->cam.pos.x * cell_size;
	cam.y = origin.y + root->cam.pos.y * cell_size;
	while (ray < nb_ray + 1)
	{
		ray_var.h_angle = root->cam.view_angle.x + (root->cam.vision.x * (ray / nb_ray - 0.5));

		init_ray(&ray_var, root);
		len = cast_ray_dda(&ray_var, root);
		ray_var.point.x = ray_var.point.x * cell_size + origin.x;
		ray_var.point.y = ray_var.point.y * cell_size + origin.y;
		draw_disk(&root->img.grid, ray_var.point, 2, 0x00ff0000);
		draw_ligne(&root->img.grid, cam, ray_var.h_angle, len * cell_size, 0xffffffff);
		ray++;
	}
}
