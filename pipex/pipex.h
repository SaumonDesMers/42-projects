#ifndef PIPEX_H
# define PIPEX_H

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
	t_bool	here_doc;
	int		nb_cmd;
	int		(*pipe)[2];
	int		fd_input;
	int		fd_output;
}	t_root;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	**env;
}	t_cmd;

void	check_input(char **av, t_root *root);

void	open_and_malloc(int ac, char **av, t_root *root);
void	heredoc_or_not(char **av, t_root *root);
void	exec_all_cmd_(char **av, int fd_in, t_root *root);

void	get_cmd(t_cmd *cmd, char *arg);
char	*get_path(char *cmd);
int		exec_cmd(char *arg, int fd_in, int fd_out, t_root *root);
void	free_cmd_arg(t_cmd cmd, int fd_in, int fd_out);

int		count_cmd(int ac, char **av, t_root *root);
void	error_catch(t_bool test, char *error_msg, t_root *root);
void	free_root(t_root *root);

char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **strs);
char	**ft_split(const char *str, char c);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_gnl(int fd, char **line);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);

#endif