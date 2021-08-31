#include "minishell.h"

void	get_cmd(t_cmd *cmd, char *str_cmd)
{
	cmd->args = ft_split(str_cmd, ' ');
	// cmd->cmd = get_cmd_path(cmd->args[0]);
	cmd->cmd = ft_strdup(cmd->args[0]);
}

char	*get_cmd_path(char *cmd)
{
	char	**path;
	char	*path_cmd;
	int		i;
	int		fd;

	fd = open(cmd, O_WRONLY);
	if (fd != -1)
	{
		close(fd);
		return (ft_strdup(cmd));
	}
	path = ft_split(getenv("PATH"), ':');
	if (path == NULL)
		return (NULL);
	i = 0;
	while (path[i])
	{
		path_cmd = ft_strjoin(ft_strjoin(path[i++], "/"), cmd);
		if (path_cmd == NULL)
			return (NULL);
		fd = open(path_cmd, O_WRONLY);
		if (fd != -1)
		{
			close(fd);
			free_split(path);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free_split(path);
	return (NULL);
}

int	exec_cmd(char *str_cmd, int fd_in, int fd_out, t_root *root)
{
	int		pid;
	t_cmd	cmd;
	int		retval;

	error_catch(str_cmd[0] == 0, "empty command", root);
	get_cmd(&cmd, str_cmd);
	if (cmd.cmd == 0 || cmd.args == 0)
	{
		free_cmd_arg(cmd, fd_in, fd_out);
		error_catch(1, "problem with cmd or malloc fail", root);
	}
	pid = fork();
	error_catch(pid == -1, "fail to create fork", root);
	if (pid == 0)
	{
		if (fd_in != 0)
			error_catch(dup2(fd_in, 0) == -1, "dup2 fail for fd_in", root);
		if (fd_out != 1)
			error_catch(dup2(fd_out, 1) == -1, "dup2 fail for fd_out", root);
		execve(cmd.cmd, cmd.args, root->shell_env);
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
}
