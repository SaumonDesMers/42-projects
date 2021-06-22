#include "pipex.h"

void	get_cmd(char **cmd, char ***args, char ***env, char *arg)
{
	*args = ft_split(arg, ' ');
	*cmd = ft_strjoin("/bin/", *args[0]);
	*env = malloc(sizeof(char **) * 1);
	*env[0] = NULL;
}

int	exec_cmd(char *arg, int fd_in, int fd_out, t_root *root)
{
	int		pid;
	char	*cmd;
	char	**args;
	char	**env;

	error_catch(arg[0] == 0, "empty command", root);
	get_cmd(&cmd, &args, &env, arg);
	if (cmd == 0 || args == 0 || env == 0)
	{
		free_cmd_arg(cmd, args, env);
		error_catch(1, "malloc fail", root);
	}
	pid = fork();
	error_catch(pid == -1, "fail to create fork", root);
	if (pid == 0)
	{
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		execve(cmd, args, env);
		error_catch(1, cmd, root);
		return (-1);
	}
	free_cmd_arg(cmd, args, env);
	return (0);
}

void	free_cmd_arg(char *cmd, char **args, char **env)
{
	free(cmd);
	free_split(args);
	free_split(env);
}
