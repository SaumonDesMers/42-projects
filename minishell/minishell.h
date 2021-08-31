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

typedef int	t_bool;

typedef struct s_root
{
	int		(*pipe)[2];
	int		pipe_index;
	char	**shell_env;
}	t_root;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
}	t_cmd;

typedef struct s_list
{
	char			*str;
	char			*sym;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	open_and_malloc(t_list *lst, t_root *root);
void	exec_all_cmd(t_list *lst, t_root *root);

void	get_cmd(t_cmd *cmd, char *arg);
char	*get_cmd_path(char *cmd);
int		exec_cmd(char *arg, int fd_in, int fd_out, t_root *root);
void	free_cmd_arg(t_cmd cmd, int fd_in, int fd_out);

char	**get_arg(char *arg);

char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **strs);
char	**ft_split(const char *str, char c);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_gnl(int fd, char **line);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);

void	error_catch(t_bool test, char *error_msg, t_root *root);
void	free_root(t_root *root);

#endif