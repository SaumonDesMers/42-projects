/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:37:26 by pguignie          #+#    #+#             */
/*   Updated: 2021/09/09 14:51:14 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir	*ft_cmdlast(t_cmd *cmd)
{
	t_redir	*redir;

	redir = cmd->redir;
	while (redir->next)
		redir = redir->next;
	return (redir);
}

static int	ft_get_mode(char *s)
{
	if (s[0] == '>')
	{
		if (s[1] && s[1] == '>')
			return (OUT_APPEND);
		else
			return (OUT_TRUNC);
	}
	else if (s[0] == '<')
	{
		if (s[1] && s[1] == '<')
			return (IN_LIMITER);
		else
			return (IN_FILE);
	}
	return (-1);
}

static void	ft_free_split(char **split)
{
	int	i;
	
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	ft_multiple_files(char *s)
{
	int	i;
	int	quote;

	i = 0;
	while (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] == ' ')
		i++;
	quote = 0;
	while (s[i])
	{
		ft_check_quote(s[i], &quote);
		if (s[i] == ' ' && !quote)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_file_cut(char *s)
{
	int	size;
	int	quote;

	size = 0;
	while (*s == '>' || *s == '<')
		s++;
	while (*s == ' ')
		s++;
	quote = 0;
	while (s[size] && (s[size] != ' ' || quote))
		ft_check_quote(s[size++], &quote);
	return (size);
}

static char	*ft_get_first_file(char *s)
{
	char	*str;
	int		i;
	int		size;

	size = ft_get_file_cut(s);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (*s == '>' || *s == '<')
		s++;
	while (*s == ' ')
		s++;
	i = 0;
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	ft_get_beginning(char *s)
{
	int	i;
	int	quote;

	i = 0;
	while (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] == ' ')
		i++;
	quote = 0;
	while (s[i] && (s[i] != ' ' || quote))
		ft_check_quote(s[i++], &quote);
	return (i);
}

static char	*ft_get_other_files(char *s)
{
	char	*str;
	int		beg;
	int		i;

	beg = ft_get_beginning(s);
	i = 0;
	while (s[beg + i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[beg + i])
	{
		str[i] = s[beg + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static void	ft_fill_cmds(t_cmd *cmds, char *split)
{
	char	**split_two;
	char	*tmp;
	t_redir	*redir;
	int		j;

	split_two = ft_split_chevron(split);
	cmds->redir = NULL;
	j = 0;
	if (split_two[0][0] != '>' && split_two[0][0] != '<')
	{
		cmds->cmd = ft_strdup(split_two[0]);
		if (!cmds->cmd)
			return ;//METTRE FONCTION ERREUR
		j = 1;
	}
	else
		cmds->cmd = NULL;
	while (split_two[j])
	{
		redir = (t_redir *)malloc(sizeof(t_redir));
		if (!redir)
			return ;
		redir->next = NULL;
		if (!cmds->redir)
			cmds->redir = redir;
		else
			ft_cmdlast(cmds)->next = redir;
		redir->mode = ft_get_mode(split_two[j]);
		if (!ft_multiple_files(split_two[j]))
			redir->str = ft_get_first_file(split_two[j]);
		else
		{
			redir->str = ft_get_first_file(split_two[j]);
			tmp = ft_get_other_files(split_two[j]);
			cmds->cmd = ft_strjoin_malloc(cmds->cmd, tmp);
		}
		j++;
	}
	ft_free_split(split_two);
}

static void	ft_print_cmds(t_cmd **cmds)
{
	int		i;
	t_redir	*redir;

	i = 0;
	while (cmds[i])
	{
		if (cmds[i]->cmd)
			printf("commande : %s\n", cmds[i]->cmd);
		if (cmds[i]->redir)
		{
			redir = cmds[i]->redir;
			while (redir)
			{
				printf("redir : %s\n", redir->str);
				printf("        mode : %d\n", redir->mode);
				redir = redir->next;
			}
		}
		i++;
	}
}

t_cmd	*ft_parser(char *str, t_root *root)
{
	char	**split_one;
	t_cmd 	*cmds;
	int		i;

	split_one = ft_split_quote(str, '|');
	if (!split_one)
		return(NULL);//METTRE FONCTION ERREUR
	i = 0;
	while (split_one[i])
		i++;
	cmds = (t_cmd *)malloc(sizeof(t_cmd) * i);
	if (!cmds)
		return(NULL);//METTRE FONCTION ERREUR
	root->nb_of_cmd = i;
	i = 0;
	while (split_one[i])
	{
		ft_fill_cmds(&(cmds[i]), split_one[i]);
		i++;
	}
	ft_free_split(split_one);
	// ft_print_cmds(cmds);
	return(cmds);
}
