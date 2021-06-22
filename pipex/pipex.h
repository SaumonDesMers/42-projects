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

typedef int t_bool;

typedef struct	s_root
{
	int		*pid;
	int		*fd_pipe[2];
	int		fd_input;
	int		fd_output;
}	t_root;

void	get_cmd(char **cmd, char ***args, char ***env, char *arg);
int		exec_cmd(char *arg, t_root *root);

int		count_cmd(int ac);
void	error_catch(t_bool test, char *error_msg, t_root *root);
void	free_all(t_root *root);

char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **strs);
char	**ft_split(const char *str, char c);
int		ft_strlen(const char *s);

#endif