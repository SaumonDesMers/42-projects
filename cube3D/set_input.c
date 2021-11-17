#include "include_lib.h"

void	read_file(char *path_name, t_root *root)
{
	int		fd;
	char	*line;
	int		flag;
	char	**strs;
	int		i;

	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (flag)
	{
		flag = get_next_line(fd, &line);
		strs = ft_split(line, ' ');
		if (!strs[0])
			continue ;
		if (!ft_isdigit(strs[0][0]))
			set_input(strs, root);
		// else if (ft_isalpha(strs[0][0]))
		set_grid(line, root);
		i = 0;
		while (strs[i])
			free(strs[i++]);
		free(strs);
		free(line);
	}
	close(fd);
}

void	set_input(char **strs, t_root *root)
{
	if (!ft_strncmp(strs[0], "R", 1))
	{
		root->win.widht = ft_atoi(strs[1]);
		root->win.height = ft_atoi(strs[2]);
	}
	if (!ft_strncmp(strs[0], "NO", 2))
		import_img(&root->img.NO, strs[1], root);
	if (!ft_strncmp(strs[0], "SO", 2))
		import_img(&root->img.SO, strs[1], root);
	if (!ft_strncmp(strs[0], "EA", 2))
		import_img(&root->img.EA, strs[1], root);
	if (!ft_strncmp(strs[0], "WE", 2))
		import_img(&root->img.WE, strs[1], root);
	if (!ft_strncmp(strs[0], "S ", 2))
		import_img(&root->img.sprite, strs[1], root);
	if (!ft_strncmp(strs[0], "C", 1))
		get_color_input(strs[1], 'C', root);
	if (!ft_strncmp(strs[0], "F", 1))
		get_color_input(strs[1], 'F', root);
}

void	get_color_input(char *str, char flag, t_root *root)
{
	char	**strs;
	int		r;
	int		g;
	int		b;
	int		i;

	strs = ft_split(str, ',');
	if (!strs)
		exit(0);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (flag == 'F')
		root->input.f_color = create_trgb(0, r, g, b);
	if (flag == 'C')
		root->input.c_color = create_trgb(0, r, g, b);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	set_grid(char *line, t_root *root)
{
	int		i;
	char	*str[10] =  {"1111111111",
						"1000100001",
						"1000100001",
						"1000000101",
						"1110000001",
						"1000000001",
						"1000101001",
						"1001000001",
						"1001000001",
						"1111111111"};

	(void)line;
	i = 0;
	root->input.grid = malloc(sizeof(char*) * 10);
	while (i < 10)
	{
		root->input.grid[i] = malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		ft_strlcpy(root->input.grid[i], str[i], ft_strlen(str[i]) + 1);
		i++;
	}
	root->input.grid_widht = 10;
	root->input.grid_height = 10;
}

void	free_grid(t_root *root)
{
	int	i;

	i = 0;
	while (i < root->input.grid_height)
		free(root->input.grid[i++]);
	free(root->input.grid);
}

