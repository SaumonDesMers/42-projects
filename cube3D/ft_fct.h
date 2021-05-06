#ifndef FT_FCT_H
# define FT_FCT_H
/*
**rendering.c
*/
void	render_floor_ceilling(t_root *root);
void	rendering(t_root *root);
int		update_img(t_root *root);
/*
**set_input.c
*/
void	read_file(char *path_name, t_root *root);
void	set_input(char **strs, t_root *root);
void	get_color_input(char *str, char flag, t_root *root);
void	set_grid(char *line, t_root *root);
void	free_grid(t_root *root);
/*
**drawing.c
*/
void	pixel_put(t_img	*img, t_vector3 coord, int color);
void	draw_square(t_img *img, t_vector3 pos1, t_vector3 pos2, int color);
void	draw_col(t_img *img, int col, int height, int color, t_root *root);
void	draw_disk(t_img *img, t_vector3 pos, float radius, int color);
void	draw_ligne(t_img *img, t_vector3 origin, float angle, float len, int color);
void	clear_img(t_img *img, int color);
/*
**camera.c
*/
int		move_view(int x, int y, t_root *root);
void	mouve_cam_from_view(int dir, t_root *root);
/*
**divers.c
*/
void	get_data_img(t_img *img);
void	create_img(t_root *root);
void	import_img(t_img *img, char *path_name, t_root *root);
/*
**key_hook.c
*/
int		key_hook(int keycode, t_root *root);
/*
**motion_hook.c
*/
int		motion_hook(int x, int y, t_root *root);
/*
**raycasting.c
*/
float	cast_ray(float angle, t_root *root);
void	ray_casting(t_root *root);
void	ray_casting_grid(t_vector3 origin, float cell_size, t_root *root);
/*
**raycasting_dda.c
*/
void	init_ray(float h_angle, t_ray *var, t_root *root);
float	cast_ray_dda(float h_angle, t_ray *var, t_root *root);
float	height(float distance, t_root *root);
void	ray_casting_dda(t_root *root);
int		*cut_color(int *color, float height, t_root *root);
int		*wall_texture(t_ray ray_var, float height, t_root *root);
void	ray_casting_grid_dda(t_vector3 origin, float cell_size, t_root *root);
/*
**maths.c
*/
float	rad(float x);
float	normalized(float x);
float	bornes(float x, float inf, float sup);
/*
**colision.c
*/
int		detect_colision(t_vector3 coord, t_root *root);
/*
**grid.c
*/
void	print_grid(t_root *root);
void	print_wall_grid(t_vector3 origin, float cell_size, t_root *root);
void	print_cam_grid(t_vector3 origin, float cell_size, t_root *root);
void	print_cell(float cell_size, t_root *root);
/*
**read_img.c
*/
int		get_pixel_color(t_img *img, t_vector3 coord);
int		*get_col_img(t_img *img, float img_col, float height, t_root *root);
void	draw_col_img(t_img *img, int col, int height, int *color, t_root *root);

#endif