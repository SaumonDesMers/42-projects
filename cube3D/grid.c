#include "include_lib.h"

void	print_grid(t_root *root)
{
	t_vector3	origin;
	float		cell_size;

	origin.x = 100;
	origin.y = 100;
	cell_size = 50;
	(void)origin;

	clear_img(&root->img.grid, create_trgb(255, 255, 255, 255));
	print_cell(cell_size, root);
	print_wall_grid(origin, cell_size, root);
	print_cam_grid(origin, cell_size, root);
	
	//ray_casting_grid(origin, cell_size, root);
	ray_casting_grid_DDA(origin, cell_size, root);
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
			pos1.x = origin.x + i * cell_size + 1;
			pos1.y = origin.y + j * cell_size + 1;
			pos2.x = pos1.x + cell_size - 1;
			pos2.y = pos1.y + cell_size - 1;
			if (root->input.grid[i][j] == '1')
				color = create_trgb(0,200,200,200);
			if (root->input.grid[i][j] == '0')
				color = create_trgb(0,0,0,0);
			draw_square(&root->img.grid, pos1, pos2, color);
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

	draw_disk(&root->img.grid, pos, 5, 0xffffffff);
}

void	print_cell(float cell_size, t_root *root)
{
	t_vector3	pos1;
	t_vector3	pos2;
	t_vector3	coord;

	coord.x = 0;
	while (coord.x < root->win.widht)
	{
		coord.y = 0;
		while (coord.y < root->win.height)
		{
			pos1.x = coord.x + 1;
			pos1.y = coord.y + 1;
			pos2.x = pos1.x + cell_size - 1;
			pos2.y = pos1.y + cell_size - 1;
			draw_square(&root->img.grid, pos1, pos2, 0x00000000);
			coord.y += cell_size;
		}
		coord.x += cell_size;
	}
}