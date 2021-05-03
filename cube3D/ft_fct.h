#ifndef FT_FCT_H
# define FT_FCT_H
/*
**rendering.c
*/
void	render_floor_ceilling(t_root *root);
void	rendering(t_root *root);
/*
**set_input.c
*/
void	set_input(t_root *root);
void	free_grid(t_root *root);
/*
**drawing.c
*/
void	pixel_put(t_vector3 coord, int color, t_root *root);
void	draw_square(t_vector3 pos1, t_vector3 pos2, int color, t_root *root);
void	draw_col(int col, int height, int color, t_root *root);
/*
**camera.c
*/
int		move_view(int x, int y, t_root *root);
void	mouve_cam_from_view(int dir, t_root *root);
/*
**divers.c
*/
void	get_data_img(t_img *img);
int		valid_coord(t_vector3 coord, t_root *root);
int		update_img(t_root *root);
void	create_img(t_root *root);
float	rad(float x);
int		normalized(int x);
/*
**key_hook.c
*/
int		key_hook(int keycode, t_root *root);
/*
**grid.c
*/

#endif