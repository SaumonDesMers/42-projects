#include "includes.h"

static t_bool	grid_size(char *file_name, t_root *root)
{
	int		gnl_return;
	int		fd;
	char	*line;
	char	**strs;

	fd = open(file_name, O_RDONLY);
	gnl_return = ft_gnl(fd, &line);
	if (*line)
		root->grid.grid_size.y++;
	strs = ft_split(line, ' ');
	if (strs == NULL)
		return (ERROR_MALLOC);
	root->grid.grid_size.x = split_size(strs);
	free_split(strs);
	while (gnl_return != 0)
	{
		gnl_return = ft_gnl(fd, &line);
		if (*line)
			root->grid.grid_size.y++;
	}
	close(fd);
	return (SUCCESS);
}

t_bool	malloc_grid(t_root *root)
{
	int	i;

	i = 0;
	root->grid.grid = malloc(sizeof(int *) * root->grid.grid_size.y);
	if (root->grid.grid == NULL)
		return (ERROR_MALLOC);
	while (i < root->grid.grid_size.y)
	{
		root->grid.grid[i] = malloc(sizeof(int) * root->grid.grid_size.x);
		if (root->grid.grid[i] == NULL)
		{
			free_double_tab((void **)root->grid.grid, i);
			return (ERROR_MALLOC);
		}
		i++;
	}
	return (SUCCESS);
}

t_bool	save_line(char *file_line, int *grid_line)
{
	char	**strs;
	int		i;

	(void)file_line;
	(void)grid_line;
	strs = ft_split(file_line, ' ');
	if (strs == NULL)
		return (ERROR_MALLOC);
	i = 0;
	while (strs[i])
	{
		grid_line[i] = ft_atoi(strs[i]);
		i++;
	}
	return (SUCCESS);
}

t_bool	read_file(int fd, t_root *root)
{
	int		i;
	char	*line;

	i = 0;
	while (i < root->grid.grid_size.y)
	{
		ft_gnl(fd, &line);
		if (save_line(line, root->grid.grid[i]) == ERROR_MALLOC)
			return (ERROR_MALLOC);
		i++;
	}
	return (SUCCESS);
}

t_bool	open_file(char *file_name, t_root *root)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
		return (ERROR_FILE);
	if (grid_size(file_name, root) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	if (malloc_grid(root) == ERROR_MALLOC)
		return (ERROR_MALLOC);
	read_file(fd, root);
	close(fd);
	return (SUCCESS);
}
