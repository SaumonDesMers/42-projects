#include "include_lib.h"

void	print_img(t_img *screen, t_img *img, t_vector3 scale, t_vector3 rotation, t_root *root)
{
	t_vector3	img_pixel;
	t_vector3	screen_pixel;
	t_vector3	lenght;
	int			color;

	(void)root;
	(void)rotation;
	(void)lenght;

	scale.x = 0.5;
	scale.y = 0.5;

	rotation.x = 30;
	rotation.y = 0;
	rotation.z = 0;

	lenght.x = scale.x * fabs(cos(rad(rotation.x)));
	lenght.y = scale.y * fabs(cos(rad(rotation.y)));

	img_pixel.x = 0;
	screen_pixel.x = 500;
	while (img_pixel.x < img->widht)
	{
		img_pixel.y = 0;
		screen_pixel.y = 300;
		while (img_pixel.y < img->height)
		{
			color = get_pixel_color(img, img_pixel);
			pixel_put(screen, screen_pixel, color);
			img_pixel.y += 1 / lenght.y;
			screen_pixel.y += 1;
		}
		img_pixel.x += 1 / lenght.x;
		screen_pixel.x += 1;
	}
}