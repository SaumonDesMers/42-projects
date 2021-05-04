#include "include_lib.h"

void	pixel_put(t_img	*img, t_vector3 coord, int color)
{
	char	*dst;

	dst = img->addr + ((int)coord.y * img->line_length + (int)coord.x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_img *img, t_vector3 pos1, t_vector3 pos2, int color, t_root *root)
{
	t_vector3	coord;

	(void)root;
	coord.x = pos1.x;
	while (coord.x < pos2.x)
	{
		coord.y = pos1.y;
		while (coord.y < pos2.y)
		{
			pixel_put(img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}

void	draw_col(t_img *img, int col, int height, int color, t_root *root)
{
	t_vector3	coord;

	coord.x = col;
	coord.y = root->cam.horizon + height / 2;
	while (coord.y > root->cam.horizon - height / 2)
	{
		pixel_put(img, coord, color);
		coord.y--;
	}
}

void	draw_disk(t_img *img, t_vector3 pos, float radius, int color)
{
	t_vector3	coord;

	coord.x = pos.x - radius - 10;
	while (coord.x < pos.x + radius + 10)
	{
		coord.y = pos.y - radius - 10;
		while (coord.y < pos.y + radius + 10)
		{
			if (pow(coord.x - pos.x, 2) + pow(coord.y - pos.y, 2) < pow(radius, 2))
				pixel_put(img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}
/*
void	draw_ligne(t_img *img, t_vector3 pos1, t_vector3 pos2, int color)
{
	t_vector3	coord;

	coord.x = pos1.x;
	while (coord.x < pos2.x)
	{
		coord.y = pos1.y;
		while (coord.y < pos2.y)
		{
			pixel_put(img, coord, color);
			coord.y++;
		}
		coord.x++;
	}
}*/