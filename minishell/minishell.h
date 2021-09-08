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
	char			**cmd; // cmd with all arguments
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
	char	**shell_env;
}	t_root;

t_bool	open_fd(t_redir *redir);
void	close_fd(t_redir *redir);
t_bool	exec_all_cmd(t_cmd *cmds, int nb_of_cmd, t_root *root);

char	*get_cmd_path(char *cmd);
int		exec_cmd(t_cmd *cmd, t_root *root);

char	**get_arg(char *arg);

char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **strs);
char	**ft_split(const char *str, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_gnl(int fd, char **line);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);

t_bool	error_catch(t_bool test, char *str, char *error_msg);

#endif