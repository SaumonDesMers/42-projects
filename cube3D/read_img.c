#include "include_lib.h"

int	get_pixel_color(t_img *img, t_vector3 coord)
{
	char	*dst;
	int		color;

	if (coord.x < 0 || coord.x > img->widht || coord.y < 0 || coord.y > img->height)
		return (-1);
	dst = img->addr + ((int)coord.y * img->line_length + (int)coord.x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int	*wall_texture(t_ray ray_var, float height, t_root *root)
{
	int		*color;

	(void)root;
	if (ray_var.len.x <= ray_var.len.y)
	{
		if (ray_var.dir.x > 0) // EAST
			color = get_col_img(&root->img.EA, ray_var.point.y - trunc(ray_var.point.y), height, root);
		if (ray_var.dir.x < 0) // WEST
			color = get_col_img(&root->img.WE, ray_var.point.y - trunc(ray_var.point.y), height, root);
	}
	else if (ray_var.len.x > ray_var.len.y)
	{
		if (ray_var.dir.y > 0) // NORTH
			color = get_col_img(&root->img.NO, ray_var.point.x - trunc(ray_var.point.x), height, root);
		if (ray_var.dir.y < 0) // SOUTH
			color = get_col_img(&root->img.SO, ray_var.point.x - trunc(ray_var.point.x), height, root);
	}
	return (color);
}

int		*get_col_img(t_img *img, float img_col, float height, t_root *root)
/*
** img_col = colonne in %
*/
{
	t_vector3	pixel;
	int			i;
	int			j;
	int			*color;

	i = 0;
	pixel.x = trunc(img->widht * img_col);
	if (height > root->win.height)
	{
		j = (height / 2) - root->cam.horizon;
		color = malloc(sizeof(int) * (root->win.height + 1));
		if (!color)
			exit(0);
		while (i < root->win.height)
		{
			pixel.y = trunc(j * img->height / height);
			color[(int)i++] = get_pixel_color(img, pixel);
			j++;
		}
		return (color);
	}
	color = malloc(sizeof(int) * (height + 1));
	if (!color)
		exit(0);
	while (i < height)
	{
		pixel.y = trunc(i * img->height / height);
		color[(int)i++] = get_pixel_color(img, pixel);
	}
	return (color);
}

void	draw_col_img(t_img *img, int col, int height, int *color, t_root *root)
{
	t_vector3	coord;
	int			i;

	coord.x = col;
	if (/*height < root->win.height*/1)
	{
		height = bornes(height, 0, root->win.height); // a retirer si mouvement vertical camera
		coord.y = root->cam.horizon - height / 2;
		i = 0;
		while (coord.y < root->cam.horizon + height / 2 && i < height)
		{
			pixel_put(img, coord, color[i++]);
			coord.y++;
		}
	}
	else if (root->cam.view_angle.y >= 0)
	{
		coord.y = root->cam.horizon - height / 2;
		height = bornes(height, 0, root->win.height);
		i = root->cam.horizon - height / 2;
		while (coord.y < root->cam.horizon + height / 2 && i < height)
		{
			pixel_put(img, coord, color[i++]);
			coord.y++;
		}
	}
	else if (root->cam.view_angle.y < 0)
	{
		coord.y = root->cam.horizon + height / 2;
		height = bornes(height, 0, root->win.height);
		i = root->cam.horizon + height / 2;
		while (coord.y > root->cam.horizon - height / 2 && i > 0)
		{
			pixel_put(img, coord, color[i--]);
			coord.y--;
		}
	}
}