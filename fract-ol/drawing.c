#include "includes.h"

void	pixel_put(t_img *img, t_vector2 coord, int color)
{
	char	*dst;

	if (coord.x < 0 || coord.x > img->widht || coord.y < 0 || coord.y > img->height)
		return ;
	dst = img->addr + ((int)coord.y * img->line_length + (int)coord.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_img *img, t_vector2 pos1, t_vector2 pos2, int color)
{
	t_vector2	coord;

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

void	draw_disk(t_img *img, t_vector2 pos, float radius, int color)
{
	t_vector2	coord;

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

void	draw_ligne(t_img *img, t_vector2 origin, float angle, float len, int color)
/*
** angle avec l'horizontal
*/
{
	float		distance;
	t_vector2	coord;

	distance = 0;
	while (distance < len)
	{
		coord.x = origin.x + distance * cos(rad(angle));
		coord.y = origin.y + distance * sin(rad(angle));
		pixel_put(img, coord, color);
		distance += 1;
	}
}

void	clear_img(t_img *img, int color)
{
	t_vector2	pos1;
	t_vector2	pos2;

	pos1.x = 0;
	pos1.y = 0;
	pos2.x = img->widht;
	pos2.y = img->height;
	draw_square(img, pos1, pos2, color);
}
