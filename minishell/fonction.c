/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:18:01 by sgaubert          #+#    #+#             */
/*   Updated: 2021/09/09 15:18:12 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		wait_process(t_cmd *cmds, int nb_of_cmd)
{
	int	i;
	int	status;

	i = 0;
	while (i < nb_of_cmd)
		waitpid(cmds[i++].pid, &status, 0);
	return (status);
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
			cmds[i].fd_in = select_fd_in(&cmds[i], i, pipe_fd);
			cmds[i].fd_out = select_fd_out(&cmds[i], i, pipe_fd, nb_of_cmd);
			exec_cmd(&cmds[i], root);
			close_fd(cmds[i].redir);
		}
		i++;
	}
	i = 0;
	while (i < nb_of_cmd - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i++][1]);
	}
	return (wait_process(cmds, nb_of_cmd));
}
