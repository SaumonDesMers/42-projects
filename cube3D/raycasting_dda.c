#include "include_lib.h"

void	init_ray(float h_angle, t_ray *var, t_root *root)
{
	var->dir.x = cos(rad(h_angle));
	var->dir.y = sin(rad(h_angle));

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

float	cast_ray_dda(float h_angle, t_ray *var, t_root *root)
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

void	ray_casting_dda(t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	t_ray		ray_var;
	int			*color;

	nb_ray = root->win.widht;
	ray = 0;
	vision = 60;
	while (ray < nb_ray)
	{
		h_angle = root->cam.view_angle.x + ((ray / nb_ray * vision) - vision / 2);

		init_ray(h_angle, &ray_var, root);
		len = cast_ray_dda(h_angle, &ray_var, root);
		len = bornes(height(len, root), 0, root->win.height);

		color = wall_texture(ray_var, len, root);
		draw_col_img(&root->img.maze, ray, len, color, root);

		free(color);
		ray++;
	}
}

int	*wall_texture(t_ray ray_var, float height, t_root *root)
{
	int		*color;

	(void)root;
	if (ray_var.len.x <= ray_var.len.y)
	{
		if (ray_var.dir.x > 0) // EAST
			color = get_col_img(&root->img.EA, ray_var.point.y - trunc(ray_var.point.y), height);
		if (ray_var.dir.x < 0) // WEST
			color = get_col_img(&root->img.WE, ray_var.point.y - trunc(ray_var.point.y), height);
	}
	else if (ray_var.len.x > ray_var.len.y)
	{
		if (ray_var.dir.y > 0) // NORTH
			color = get_col_img(&root->img.NO, ray_var.point.x - trunc(ray_var.point.x), height);
		if (ray_var.dir.y < 0) // SOUTH
			color = get_col_img(&root->img.SO, ray_var.point.x - trunc(ray_var.point.x), height);
	}
	return (color);
}

void	ray_casting_grid_dda(t_vector3 origin, float cell_size, t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	t_ray		ray_var;
	t_vector3	cam;

	(void)len;
	(void)h_angle;
	(void)cam;
	ray = 0;
	vision = 60;
	nb_ray = vision;
	cam.x = origin.x + root->cam.pos.x * cell_size;
	cam.y = origin.y + root->cam.pos.y * cell_size;
	while (ray < nb_ray + 1)
	{
		h_angle = root->cam.view_angle.x + ((ray / nb_ray * vision) - vision / 2);

		init_ray(h_angle, &ray_var, root);
		len = cast_ray_dda(h_angle, &ray_var, root);
		ray_var.point.x = ray_var.point.x * cell_size + origin.x;
		ray_var.point.y = ray_var.point.y * cell_size + origin.y;
		draw_disk(&root->img.grid, ray_var.point, 2, 0x00ff0000);
		draw_ligne(&root->img.grid, cam, h_angle, len * cell_size, 0xffffffff);
		ray++;
	}
}