#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_vector3 {
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef struct	s_mlx_win {
	void	*win;
	int		height;
	int		widht;
}				t_mlx_win;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		widht;
	int		height;
}				t_img;

typedef struct	s_camera {
	t_vector3	pos;
	t_vector3	view_angle;
	int			horizon;
	t_img		img;
	t_img		img_grid;
}				t_camera;

typedef struct	s_input {
	char		**grid;
	int			grid_widht;
	int			grid_height;
	t_img		NO_img;
	t_img		SO_img;
	t_img		WE_img;
	t_img		EA_img;
	t_img		sprite_img;
	int			c_color;
	int			f_color;
}				t_input;

typedef struct	s_root {
	void		*mlx;
	t_mlx_win	win;
	t_camera	cam;
	t_input		input;
}				t_root;

#endif