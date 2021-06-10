#ifndef FT_FCT_H
# define FT_FCT_H
/*
** rendering.c
*/
// void	rendering(t_root *root);
// int		update_img(t_root *root);

/*
** drawing.c
*/
void	pixel_put(t_img	*img, t_vector2 coord, int color);
void	draw_square(t_img *img, t_vector2 pos1, t_vector2 pos2, int color);
void	draw_disk(t_img *img, t_vector2 pos, float radius, int color);
void	draw_ligne(t_img *img, t_vector2 origin, float angle, float len, int color);
void	clear_img(t_img *img, int color);

/*
** divers.c
*/
void	get_data_img(t_img *img);
int		create_img(t_img *img, float widht, float height, t_root *root);

/*
** key_hook.c
*/
int		key_hook(int keycode, t_root *root);

/*
** maths.c
*/
float	rad(float x);
float	deg(float x);
float	normalized(float x);
float	bornes(float x, float inf, float sup);
void	cart_pol(float *r, float *i, float *arg, float *mod, char op);

/*
** complexe.c
*/
void	set_c(t_complexe *c, float r, float i);
void	add_c(t_complexe *rst, t_complexe c1, t_complexe c2);
void	mult_c(t_complexe *rst, t_complexe c1, t_complexe c2);

/*
** julia.c
*/
int		julia_serie(t_complexe c);
int		julia(t_root *root);

// void	manipulate_img(t_root *root);
// void	print_img(t_img *screen, t_img *img, t_vector2 scale, t_vector2 rotation, t_root *root);

#endif