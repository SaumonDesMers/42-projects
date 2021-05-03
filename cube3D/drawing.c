#include "include_lib.h"

void	pixel_put(t_vector3 coord, int color, t_root *root)
{
	char	*dst;
	t_img	*img;

	if (!valid_coord(coord, root))
		return ;
	img = &root->cam.img;
	dst = img->addr + ((int)coord.y * img->line_length + (int)coord.x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_vector3 pos1, t_vector3 pos2, int color, t_root *root)
{
	t_vector3	coord;

	coord.x = pos1.x;
	while (coord.x < pos2.x)
	{
		coord.y = pos1.y;
		while (coord.y < pos2.y)
		{
			pixel_put(coord, color, root);
			coord.y++;
		}
		coord.x++;
	}
}

void	draw_col(int col, int height, int color, t_root *root)
{
	t_vector3	coord;

	coord.x = col;
	coord.y = root->cam.horizon + height / 2;
	while (coord.y > root->cam.horizon - height / 2)
	{
		pixel_put(coord, color, root);
		coord.y--;
	}
}