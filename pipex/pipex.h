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

void	get_cmd(char **cmd, char ***args, char ***env, char *arg);
void	exec_cmd(char *arg);

int		count_cmd(int ac);
void	error_catch(int test_value, int error_value, char *error_msg);

char	*ft_strjoin(char const *s1, char const *s2);
void	free_split(char **strs);
char	**ft_split(const char *str, char c);
int		ft_strlen(const char *s);

#endif