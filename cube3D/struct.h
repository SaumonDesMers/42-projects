#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_root {
	t_vars	vars;
	t_data	img;
}				t_root;

#endif