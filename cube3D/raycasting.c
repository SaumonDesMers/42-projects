#include "include_lib.h"

float	cast_ray(float angle, t_root *root)
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
		coord.x = cam.x + distance * cos(rad(root->cam.view_angle.x - angle));
		coord.y = cam.y + distance * sin(rad(root->cam.view_angle.x - angle));
		char_grid = root->input.grid[(int)trunc(coord.x)][(int)trunc(coord.y)];
		distance += 0.001;
	}
	distance = distance * cos(rad(angle));
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
	float	distance;
	float	angle_ray;
	t_vector3	point;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	nb_ray = root->win.widht;
	ray = 0;
	vision_angle = 60;
	// while (ray < nb_ray + 1)
	// {
	// 	distance = cast_ray((ray / nb_ray * vision_angle) - vision_angle / 2, root);
	// 	printf("angle : %.2f\t distance : %.2f\n", ray / nb_ray * vision_angle - vision_angle / 2, distance);
	// 	if (distance != -1)
	// 		draw_col(ray / nb_ray * root->win.widht, height(distance, root), 0xffffffff, root);
	// 	ray++;
	// }
	while (ray < nb_ray + 1)
	{
		angle_ray = root->cam.view_angle.x + (ray / nb_ray * vision_angle) - vision_angle / 2;
		distance = cast_ray_DDA(angle_ray, &point, root);
		distance = distance * cos(rad((ray / nb_ray * vision_angle)));
		//printf("angle : %.2f\t distance : %.2f\n", angle_ray, distance);
		if (distance != -1)
			draw_col(&root->cam.img, ray, height(distance, root), 0xffffffff, root);
		ray++;
	}
}