#include "include_lib.h"

float	cast_ray(float v_angle, t_root *root)
{
	float		distance;
	char		char_grid;
	t_vector3	coord;
	t_vector3	cam;

	cam.x = root->cam.pos.x;
	cam.y = root->cam.pos.y;
	distance = 0;
	char_grid = '0';
	while (char_grid == '0')
	{
		coord.x = cam.x + distance * cos(rad(root->cam.view_angle.x - v_angle));
		coord.y = cam.y + distance * sin(rad(root->cam.view_angle.x - v_angle));
		char_grid = root->input.grid[(int)trunc(coord.x)][(int)trunc(coord.y)];
		distance += 0.001;
	}
	distance = distance * cos(rad(v_angle));
	return (distance);
}

float	height(float distance, t_root *root)
{
	float	height;

	height = (root->win.height / 2) / distance;
	return (height);
}

void	ray_casting(t_root *root)
{
	int		nb_ray;
	float	ray;
	float	vision_angle;
	float	len;

	nb_ray = root->win.widht;
	ray = 0;
	vision_angle = 60;
	while (ray < nb_ray + 1)
	{
		len = cast_ray((ray / nb_ray * vision_angle) - vision_angle / 2, root);
		//printf("angle : %.2f\t len : %.2f\n", ray / nb_ray * vision_angle - vision_angle / 2, len);
		if (len != 0)
			draw_col(&root->img.maze, ray, height(len, root), 0xffffffff, root);
		ray++;
	}
	
}

void	ray_casting_grid(t_vector3 origin, float cell_size, t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		len;
	float		h_angle; // angle avec l'horizontal
	float		v_angle; // angle avec l'angle de vue

	nb_ray = 10;
	ray = 0;
	vision = 60;
	origin.x = origin.x + root->cam.pos.x * cell_size;
	origin.y = origin.y + root->cam.pos.y * cell_size;
	while (ray < nb_ray)
	{
		v_angle = (ray / nb_ray * vision) - vision / 2;
		h_angle = root->cam.view_angle.x - v_angle;

		len = cast_ray(v_angle, root);
		len = len / cos(rad(v_angle));
		draw_ligne(&root->img.grid, origin, h_angle, len * cell_size, 0x00ff0000);
		ray++;
	}
}