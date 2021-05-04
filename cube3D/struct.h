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
}				t_camera;

typedef struct	s_input {
	char		**grid;
	int			grid_widht;
	int			grid_height;
	int			c_color;
	int			f_color;
}				t_input;

typedef struct	s_list_img {
	t_img		maze;
	t_img		grid;
	t_img		NO;
	t_img		SO;
	t_img		WE;
	t_img		EA;
	t_img		sprite;
}				t_list_img;

typedef struct	s_root {
	void		*mlx;
	t_mlx_win	win;
	t_camera	cam;
	t_input		input;
	t_list_img	img;
}				t_root;

typedef struct	s_DDA {
	t_vector3	dir;
	t_vector3	step;
	t_vector3	delta;
	t_vector3	len;
	t_vector3	point;
	int			cell[2];
}				t_DDA;

#endif