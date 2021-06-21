#include "pipex.h"

void	get_cmd(char **cmd, char ***args, char ***env, char *arg)
{
	*args = ft_split(arg, ' ');
	error_catch((int)*args, 0, "Malloc error");
	*cmd = ft_strjoin("/bin/", *args[0]);
	error_catch((int)*cmd, 0, "Malloc error");
	*env = malloc(sizeof(char **) * 1);
	error_catch((int)*env, 0, "Malloc error");
	*env[0] = NULL;
}

void	exec_cmd(char *arg)
{
	int		pid;
	char	*cmd;
	char	**args;
	char	**env;

	get_cmd(&cmd, &args, &env, arg);
	pid = fork();
	error_catch(pid, -1, "Error fork");
	if (pid == 0)
	{
		execve(cmd, args, env);
		write(2, "Command not found", 17);
	}
	free(cmd);
	free_split(args);
	free_split(env);
}
