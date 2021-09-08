#include "minishell.h"

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

int	exec_cmd(t_cmd *cmd, t_root *root)
{
	char	*cmd_path;

	if (cmd->cmd[0] == NULL)
		return (SUCCESS);

	// cmd_path = get_cmd_path(cmd->cmd[0]);
	cmd_path = ft_strdup(cmd->cmd[0]);

	printf("[%d] -> %s -> [%d]\n", cmd->fd_in, cmd_path, cmd->fd_out);
	if (error_catch(cmd_path == NULL, "system", "fail to malloc cmd_path"))
		exit(1);
	cmd->pid = fork();
	error_catch(cmd->pid == -1, "system", "fail to create fork");
	if (cmd->pid == 0)
	{
		if (error_catch(dup2(cmd->fd_in, 0) == -1, "system", "dup2 fail"))
			exit(ERROR);
		if (error_catch(dup2(cmd->fd_out, 1) == -1, "system", "dup2 fail"))
			exit(ERROR);
		execve(cmd_path, cmd->cmd, root->shell_env);	
		free(cmd_path);
		error_catch(1, cmd->cmd[0], "some problem has occured");
		exit(ERROR);
	}
	free(cmd_path);
	return (SUCCESS);
}
