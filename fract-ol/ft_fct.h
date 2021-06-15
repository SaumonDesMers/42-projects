#ifndef FT_FCT_H
# define FT_FCT_H

/*
** drawing.c
*/
void	pixel_put(t_img	*img, t_vector2 coord, int color);

/*
** divers.c
*/
void	get_data_img(t_img *img);
int		create_img(t_img *img, float widht, float height, t_root *root);
int		input(int ac, char **av, t_root *root);
int		update_img(t_root *root);

/*
** key_hook.c
*/
int		key_hook(int keycode, t_root *root);

/*
** mouse_hook.c
*/
int		mouse_hook(int button, int x, int y, t_root *root);

/*
** maths.c
*/
float	rad(float x);
float	deg(float x);
float	normalized(float x);
float	bornes(float x, float inf, float sup);

/*
** complexe.c
*/
void	set_c(t_complexe *c, float r, float i);
void	add_c(t_complexe *rst, t_complexe c1, t_complexe c2);
void	mult_c(t_complexe *rst, t_complexe c1, t_complexe c2);

/*
** julia.c
*/
int		julia_serie(t_complexe z, t_complexe c);
int		julia(t_complexe c, t_root *root);
void	fractal_color(int n, t_vector2 pxl, t_root *root);

/*
** mandelbrot.c
*/
int		mandelbrot_serie(t_complexe z, t_complexe c);
int		mandelbrot(t_root *root);

#endif