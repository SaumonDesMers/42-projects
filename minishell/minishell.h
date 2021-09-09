/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:18:37 by sgaubert          #+#    #+#             */
/*   Updated: 2021/09/09 15:18:41 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/src/libft.h"

typedef int	t_bool;

typedef struct s_cmd
{
	char			*cmd; // cmd with all arguments
	int				pid;
	int				fd_in;
	int				fd_out;
	struct s_redir	*redir; // list of all redirection in the same order as writen in the command line
}	t_cmd;

typedef struct s_redir
{
	int				mode; // OUT_TRUNC, OUT_APPEND, IN_FILE, IN_LIMITER
	char			*str; // nom du file ou limiter
	int				fd;
	struct s_redir	*next;
}	t_redir;

enum e_redir_mode
{
	OUT_TRUNC = O_TRUNC, // >
	OUT_APPEND = O_APPEND, // >>
	IN_FILE, // <
	IN_LIMITER // <<
};

enum e_flag
{
	SUCCESS,
	ERROR
};

typedef struct s_root
{
	int		nb_of_cmd;
	char	**shell_env;
}	t_root;

t_bool	open_fd(t_redir *redir);
void	close_fd(t_redir *redir);
t_bool	exec_all_cmd(t_cmd *cmds, int nb_of_cmd, t_root *root);

char	*get_cmd_path(char *cmd);
int		exec_cmd(t_cmd *cmd, t_root *root);

char	**get_arg(char *arg);

int		find_last_fd_in_or_out(t_redir *redir, int test_one, int test_two);
int		select_fd_in(t_cmd *cmd, int cmd_index, int (*pipe_fd)[2]);
int		select_fd_out(t_cmd *cmd, int cmd_index, int (*pipe_fd)[2], int nb_of_cmd);

int		read_heredoc_pipe(char *limiter);
t_bool	open_fd(t_redir *redir);
void	close_fd(t_redir *redir);
int		(*open_pipe(int nb_of_cmd))[2];

t_bool	error_catch(t_bool test, char *str, char *error_msg);

void	ft_check_quote(char c, int *quote);
int		ft_check_str(char *str);
t_cmd	*ft_parser(char *str, t_root *root);
char	**ft_split_quote(const char *s, char c);
char	**ft_split_chevron(const char *s);
char	*ft_strjoin_malloc(char *s1, char *s2);

#endif
