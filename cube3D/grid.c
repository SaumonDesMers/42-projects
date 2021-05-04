#include "include_lib.h"

void	print_grid(t_root *root)
{
	t_vector3	origin;
	float		cell_size;

	origin.x = 0;
	origin.y = 0;
	cell_size = 50;

	print_wall_grid(origin, cell_size, root);
	print_cam_grid(origin, cell_size, root);
	ray_casting_grid(origin, cell_size, root);
}

void	print_wall_grid(t_vector3 origin, float cell_size, t_root *root)
{
	t_vector3	pos1;
	t_vector3	pos2;
	int			i;
	int			j;
	int			color;

	i = 0;
	while (i < root->input.grid_widht)
	{
		j = 0;
		while (j < root->input.grid_height)
		{
			pos1.x = origin.x + i * cell_size;
			pos1.y = origin.y + j * cell_size;
			pos2.x = pos1.x + cell_size;
			pos2.y = pos1.y + cell_size;
			if (root->input.grid[i][j] == '1')
				color = create_trgb(0,200,200,200);
			if (root->input.grid[i][j] == '0')
				color = create_trgb(0,0,0,0);
			draw_square(&root->cam.img_grid, pos1, pos2, color, root);
			j++;
		}
		i++;
	}
}

void	print_cam_grid(t_vector3 origin, float cell_size, t_root *root)
{
	t_vector3	pos;

	pos.x = origin.x + root->cam.pos.x * cell_size;
	pos.y = origin.y + root->cam.pos.y * cell_size;

	draw_disk(&root->cam.img_grid, pos, 5, 0xffffffff);
}

void	ray_casting_grid(t_vector3 origin, float cell_size, t_root *root)
{
	int			nb_ray;
	float		ray;
	float		vision;
	float		distance;
	t_vector3	point;
	float		angle_ray;

	nb_ray = 10;
	ray = 0;
	vision = 60;
	// while (ray < nb_ray + 1)
	// {
	// 	distance = cast_ray((ray / nb_ray * vision) - vision / 2, root);
	// 	point.x = root->cam.pos.x + distance * cos(rad(root->cam.view_angle.x + (ray / nb_ray * vision) - vision / 2));
	// 	point.y = root->cam.pos.y + distance * sin(rad(root->cam.view_angle.x + (ray / nb_ray * vision) - vision / 2));
	// 	point.x = origin.x + point.x * cell_size;
	// 	point.y = origin.y + point.y * cell_size;
	// 	pixel_put(&root->cam.img_grid, point, 0x00ff0000);
	// 	ray++;
	// }
	point.x = 0;
	point.y = 0;
	point.z = 0;
	while (ray < nb_ray + 1)
	{
		angle_ray = root->cam.view_angle.x + (ray / nb_ray * vision) - vision / 2;
		distance = cast_ray_DDA(angle_ray, &point, root);
		distance = distance * cos(rad((ray / nb_ray * vision)));

		point.x = origin.x + point.x * cell_size;
		point.y = origin.y + point.y * cell_size;

		pixel_put(&root->cam.img_grid, point, 0x00ff0000);
		ray++;
	}
}