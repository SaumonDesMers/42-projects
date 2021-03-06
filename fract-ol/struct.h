#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector2 {
	double	x;
	double	y;
}				t_vector2;

typedef struct s_complexe {
	double	r;
	double	i;
}				t_complexe;

typedef struct s_mlx_win {
	void	*win;
	int		height;
	int		widht;
}				t_mlx_win;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		widht;
	int		height;
}				t_img;

typedef struct s_grid {
	t_img		img;
	t_vector2	pos_cam;
	double		scale;
	t_vector2	pos_mouse;
	t_complexe	c;
	int			color;
}				t_grid;

typedef struct s_root {
	void		*mlx;
	t_mlx_win	win;
	t_grid		grid;
	char		set;
}				t_root;

#endif