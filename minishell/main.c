/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:06:15 by pguignie          #+#    #+#             */
/*   Updated: 2021/09/09 14:48:12 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmds(t_cmd **cmds)
{
	int		i;
	t_redir	*redir;
	t_redir	*tmp;

	i = 0;
	while (cmds[i])
	{
		if (cmds[i]->cmd)
			free(cmds[i]->cmd);
		if (cmds[i]->redir)
		{
			redir = cmds[i]->redir;
			while (redir)
			{
				free(redir->str);
				tmp = redir;
				redir = redir->next;
				free(tmp);
			}
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_root	root;
	t_cmd	*cmds;

	root.shell_env = envp;
	cmds = NULL;
	(void)argv;
	if (argc == 1)
	{
		while (1)
		{
			str = readline("> ");
			if (!ft_strncmp(str, "exit", ft_strlen(str)))
				return (0);
			if (!ft_check_str(str))
			{
				ft_putstr_fd("Quote Error.\n", 2);
				free(str);
			}
			else
			{
				cmds = ft_parser(str, &root);
				exec_all_cmd(cmds, root.nb_of_cmd, &root);
				free(cmds);
			}
		}
	}
	return (0);
}
