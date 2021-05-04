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
void	set_input(t_root *root);
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
float	height(float distance, t_root *root);
void	ray_casting(t_root *root);
void	ray_casting_grid(t_vector3 origin, float cell_size, t_root *root);
/*
**DDA.c
*/
void	init_DDA(float h_angle, t_DDA *var, t_root *root);
float	cast_ray_DDA(float h_angle, t_DDA *var, t_root *root);
void	ray_casting_DDA(t_root *root);
void	ray_casting_grid_DDA(t_vector3 origin, float cell_size, t_root *root);
/*
**maths.c
*/
float	rad(float x);
float	normalized(float x);
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

#endif