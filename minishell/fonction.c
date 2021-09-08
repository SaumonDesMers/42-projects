#include "minishell.h"

int	read_heredoc_pipe(char *limiter)
{
	int		heredoc_pipe[2];
	char	*line;

	if (error_catch(pipe(heredoc_pipe) == -1, "system", "fail to open pipe"))
		return (-1);
	while (1)
	{
		line = readline(">");
		// check line not NULL
		if (!ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
			break ;
		ft_putstr_fd(line, heredoc_pipe[1]);
		ft_putstr_fd("\n", heredoc_pipe[1]);
		free(line);
		line = NULL;
	}
	free(line);
	close(heredoc_pipe[1]);
	return (heredoc_pipe[0]);
}

t_bool	open_fd(t_redir *redir)
{
	while (redir)
	{
		if (redir->mode == OUT_TRUNC || redir->mode == OUT_APPEND)
		{
			redir->fd = open(redir->str, O_WRONLY | redir->mode);
			if (redir->fd == -1)
				redir->fd = open(redir->str, O_WRONLY | O_CREAT, 0664); 
		}
		else if (redir->mode == IN_FILE)
			redir->fd = open(redir->str, O_RDONLY);
		if (redir->mode == IN_LIMITER)
		{
			redir->fd = read_heredoc_pipe(redir->str);
			if (redir->fd == -1)
				return (ERROR);
		}
		if (error_catch(redir->fd == -1, redir->str, "No such file or directory"))
			return (ERROR);
		redir = redir->next;
	}
	return (SUCCESS);
}

void	close_fd(t_redir *redir)
{
	while (redir)
	{
		if (redir->fd == -1)
			return ;
		close(redir->fd);
		redir = redir->next;
	}
}

int	(*open_pipe(int nb_of_cmd))[2]
{
	int	i;
	int	(*pipe_fd)[2];

	pipe_fd = malloc(sizeof(int [2]) * (nb_of_cmd - 1));
	if (error_catch(pipe_fd == 0, "system", "fail to malloc pipe table"))
		return (NULL);
	i = 0;
	while (i < nb_of_cmd - 1)
	{
		if (error_catch(pipe(pipe_fd[i++]) == -1, "system", "fail to open pipe"))
			return (NULL);
	}
	return (pipe_fd);
}

t_bool	exec_all_cmd(t_cmd *cmds, int nb_of_cmd, t_root *root)
{
	int	i;
	int	(*pipe_fd)[2];

	pipe_fd = open_pipe(nb_of_cmd);
	i = 0;
	while (i < nb_of_cmd)
	{
		if (open_fd(cmds[i].redir) == ERROR)
			close_fd(cmds[i].redir);
		else
		{
			// cmds[i].fd_in = select_fd_in(cmds[i], i, pipe_fd, nb_of_cmd);
			// cmds[i].fd_out = select_fd_out(cmds[i], i, pipe_fd, nb_of_cmd);
			exec_cmd(&cmds[i], root);
			close_fd(cmds[i].redir);
		}
		i++;
	}
	// close_pipe(pipe_fd);
	// return (wait_process(cmds));
	return (0);
}
