#ifndef STRUCT_H
# define STRUCT_H

typedef int	t_bool;

typedef enum e_key_word
{
	ERROR_FILE = -3,
	ERROR_MALLOC = -2,
	ERROR = -1,
	SUCCESS = 1
}	t_key_word;

typedef enum e_key_code
{
	ESCAPE = 65307
}	t_key_code;

typedef struct s_vector3 {
	double	x;
	double	y;
	double	z;
}				t_vector3;

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
	int			**grid;
	t_vector3	grid_size;
}				t_grid;

typedef struct s_root {
	void		*mlx;
	t_mlx_win	win;
	t_grid		grid;
	t_img		img;
}				t_root;

#endif