#include "pipex.h"

void	open_and_malloc(int ac, char **av, t_root *root)
{
	int	i;

	root->pipe = 0;
	root->fd_input = 0;
	root->fd_output = 0;
	if (root->here_doc == 0)
		root->fd_input = open(av[1], O_RDONLY);
	error_catch(root->fd_input == -1, "fail to open input file", root);
	if (access(av[ac - 1], F_OK) == -1)
		root->fd_output = open(av[ac - 1], O_CREAT | O_WRONLY, 0644); // check permission on vm
	else if (root->here_doc == 0)
		root->fd_output = open(av[ac - 1], O_WRONLY | O_TRUNC);
	else if (root->here_doc == 1)
		root->fd_output = open(av[ac - 1], O_WRONLY | O_APPEND);
	error_catch(root->fd_output == -1, "fail to open output file", root);
	if (root->nb_cmd > 0)
	{
		root->pipe = malloc(sizeof(int [2]) * (root->nb_cmd - 1));
		error_catch(root->pipe == 0, "fail to malloc pipe list", root);
	}
	i = 0;
	while (i < root->nb_cmd)
		error_catch(pipe(root->pipe[i++]) == -1, "fail to open pipe", root);
}

void	heredoc_or_not(char **av, t_root *root)
{
	int		heredoc_pipe[2];
	char	*line;
	char	gnl_return;

	if (root->here_doc == 1)
	{
		error_catch(pipe(heredoc_pipe) == -1, "fail to open pipe", root);
		gnl_return = 1;
		while (gnl_return)
		{
			gnl_return = ft_gnl(0, &line);
			if (!ft_strncmp(line, av[2], ft_strlen(av[2]) + 1))
				break ;
			ft_putstr_fd(line, heredoc_pipe[1]);
			ft_putstr_fd("\n", heredoc_pipe[1]);
			free(line);
			line = NULL;
		}
		free(line);
		close(heredoc_pipe[1]);
		exec_all_cmd_(av, heredoc_pipe[0], root);
	}
	else
		exec_all_cmd_(av, root->fd_input, root);
}

void	exec_all_cmd_(char **av, int fd_in, t_root *root)
{
	int		i;
	int		i_cmd;

	i_cmd = root->here_doc + 2;
	if (root->nb_cmd == 0)
		exec_cmd("/bin/cat", fd_in, root->fd_output, root);
	else if (root->nb_cmd == 1)
		exec_cmd(av[i_cmd], fd_in, root->fd_output, root);
	else
	{
		exec_cmd(av[i_cmd], fd_in, root->pipe[0][1], root);
		i = 1;
		while (i < root->nb_cmd - 1)
		{
			exec_cmd(av[i + i_cmd], root->pipe[i - 1][0],
				root->pipe[i][1], root);
			i++;
		}
		exec_cmd(av[i + i_cmd], root->pipe[i - 1][0], root->fd_output, root);
	}
}
