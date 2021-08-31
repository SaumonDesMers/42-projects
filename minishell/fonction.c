#include "minishell.h"

void	open_and_malloc(t_list *lst, t_root *root)
{
	int	i;
	int	nb_pipe;

	nb_pipe = 0;
	while (lst)
	{
		if (lst->sym && ft_strncmp(lst->sym, "|", 2) == 0)
			nb_pipe++;
		lst = lst->next;
	}

	if (nb_pipe > 0)
	{
		root->pipe = malloc(sizeof(int [2]) * (nb_pipe - 1));
		error_catch(root->pipe == 0, "fail to malloc pipe list", root);
	}
	i = 0;
	while (i < nb_pipe)
		error_catch(pipe(root->pipe[i++]) == -1, "fail to open pipe", root);
}

int	select_fd_in(t_list *lst, t_root *root)
{
	int		fd_in;
	int		heredoc_pipe[2];
	char	*line;

	fd_in = 0;
	if (lst->sym && ft_strncmp(lst->sym, "<", 2) == 0)
	{
		fd_in = open(lst->next->str, O_RDONLY);
		error_catch(fd_in == -1, "fail to open input file", root);
	}
	else if (lst->sym && ft_strncmp(lst->sym, "<<", 3) == 0)
	{
		error_catch(pipe(heredoc_pipe) == -1, "fail to open pipe", root);
		while (1)
		{
			line = readline("pipe heredoc>");
			if (!ft_strncmp(line, lst->next->str, ft_strlen(lst->next->str) + 1))
				break ;
			ft_putstr_fd(line, heredoc_pipe[1]);
			ft_putstr_fd("\n", heredoc_pipe[1]);
			free(line);
			line = NULL;
		}
		free(line);
		close(heredoc_pipe[1]);
		fd_in = heredoc_pipe[0];
	}
	else if (lst->prev == NULL)
		return (fd_in);
	else if (ft_strncmp(lst->prev->sym, "|", 2) == 0)
		fd_in = root->pipe[root->pipe_index][0];
	return (fd_in);
}

int	select_fd_out(t_list *lst, t_root *root)
{
	int	fd_out;

	fd_out = 1;
	if (lst->sym == NULL)
		return (fd_out);
	else if (ft_strncmp(lst->sym, "|", 2) == 0)
	{
		printf("{%d}\n", root->pipe[root->pipe_index][1]);
		fd_out = root->pipe[root->pipe_index++][1];
		printf("a\n");
	}
	else if (ft_strncmp(lst->sym, ">", 2) == 0)
	{
		fd_out = open(lst->next->str, O_WRONLY | O_TRUNC);
		if (fd_out == -1)
			fd_out = open(lst->next->str, O_WRONLY | O_CREAT, 0664);
		error_catch(fd_out == -1, "fail to open output file", root);
	}
	else if (ft_strncmp(lst->sym, ">>", 3) == 0)
	{
		fd_out = open(lst->next->str, O_WRONLY | O_APPEND);
		if (fd_out == -1)
			fd_out = open(lst->next->str, O_WRONLY | O_CREAT, 0664);
		error_catch(fd_out == -1, "fail to open output file", root);
	}
	else if (ft_strncmp(lst->sym, "<<", 3) == 0)
	{
		fd_out = select_fd_out(lst->next, root);
	}
	return (fd_out);
}

t_bool	is_file_or_limiter(t_list *lst)
{
	t_bool	retval;

	retval = 0;
	if (lst->prev && ft_strncmp(lst->prev->sym, ">", 2) == 0)
		retval = 1;
	else if (lst->prev && ft_strncmp(lst->prev->sym, "<", 2) == 0)
		retval = 1;
	else if (lst->prev && ft_strncmp(lst->prev->sym, ">>", 3) == 0)
		retval = 1;
	else if (lst->prev && ft_strncmp(lst->prev->sym, "<<", 3) == 0)
		retval = 1;
	return (retval);
}

void	exec_all_cmd(t_list *lst, t_root *root)
{
	int		i;
	int		fd_in = 0;
	int		fd_out = 0;

	root->pipe_index = 0;
	i = 0;
	while (lst)
	{
		if (!is_file_or_limiter(lst))
		{
			fd_out = select_fd_out(lst, root);
			fd_in = select_fd_in(lst, root);
			printf("\n[%d] -> %s -> [%d]\n", fd_in, lst->str, fd_out);
			exec_cmd(lst->str, fd_in, fd_out, root);
		}
		lst = lst->next;
	}
	waitpid(-1, NULL, 0);
}
