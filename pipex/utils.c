#include "pipex.h"

int	count_cmd(int ac)
{
	if (ac < 3)
		return (-1);
	return (ac - 3);
}

void	error_catch(t_bool test, char *error_msg, t_root *root)
{
	if (test)
	{
		write(2, "Error : ", 8);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
		free_root(root);
		exit(0);
	}
}

void	free_root(t_root *root)
{
	free(root->pipe);
	if (root->fd_input != -1)
		close(root->fd_input);
	if (root->fd_output != -1)
		close(root->fd_output);
}
