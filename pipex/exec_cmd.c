#include "pipex.h"

void	get_cmd(t_cmd *cmd, char *arg)
{
	cmd->args = ft_split(arg, ' ');
	cmd->cmd = ft_strjoin("", cmd->args[0]);
	cmd->env = malloc(sizeof(char **) * 1);
	cmd->env[0] = NULL;
}

int	exec_cmd(char *arg, int fd_in, int fd_out, t_root *root)
{
	int		pid;
	t_cmd	cmd;

	error_catch(arg[0] == 0, "empty command", root);
	get_cmd(&cmd, arg);
	if (cmd.cmd == 0 || cmd.args == 0 || cmd.env == 0)
	{
		free_cmd_arg(cmd, fd_in, fd_out);
		error_catch(1, "malloc fail", root);
	}
	pid = fork();
	error_catch(pid == -1, "fail to create fork", root);
	if (pid == 0)
	{
		error_catch(dup2(fd_in, 0) == -1, "dup2 fail for fd_in", root);
		error_catch(dup2(fd_out, 1) == -1, "dup2 fail for fd_out", root);
		execve(cmd.cmd, cmd.args, cmd.env);
		error_catch(1, cmd.cmd, root);
		return (-1);
	}
	free_cmd_arg(cmd, fd_in, fd_out);
	return (0);
}

void	free_cmd_arg(t_cmd cmd, int fd_in, int fd_out)
{
	close(fd_in);
	close(fd_out);
	free(cmd.cmd);
	free_split(cmd.args);
	free_split(cmd.env);
}
