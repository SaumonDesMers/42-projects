#include "include_lib.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_data_img(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

int	click(int button, int x, int y, t_root *root)
{
	(void)button;
	my_mlx_pixel_put(&root->img, x, y, create_trgb(0, 255, 255, 255));
	mlx_put_image_to_window(root->vars.mlx, root->vars.win, root->img.img, 0, 0);
	return (0);
}

int	esc_close(int keycode, t_root *root)
{
	(void)root;
	if (keycode == 65307)
		mlx_destroy_window(root->vars.mlx, root->vars.win);
	return (0);
}

int	press_space(int keycode, t_root *root)
{
	(void)root;
	if (keycode == 32)
		printf("space\n");
	return (0);
}

int	main(void)
{
	t_root		root;

	root.vars.mlx = mlx_init();
	root.vars.win = mlx_new_window(root.vars.mlx, 1920, 1080, "salut");

	root.img.img = mlx_new_image(root.vars.mlx, 1920, 1080);
	get_data_img(&root.img);
	
	
	//mlx_mouse_hook(root.vars.win, click, &root);

	mlx_key_hook(root.vars.win, esc_close, &root);

	mlx_hook(root.vars.win, 2, 1L<<0, press_space, &root);

	mlx_hook(root.vars.win, 6, 1L<<13, click, &root);

	mlx_loop(root.vars.mlx);

	return (0);
}