#include "includes.h"

void	pixel_put(t_img *img, t_vector2 coord, int color)
{
	char	*dst;

	if (coord.x < 0 || coord.x > img->widht
		|| coord.y < 0 || coord.y > img->height)
		return ;
	dst = img->addr + ((int)coord.y * img->line_length
			+ (int)coord.x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
