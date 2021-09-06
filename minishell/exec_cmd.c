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

int	exec_cmd(t_ast *ast, int fd_in, int fd_out, t_root *root)
{
	char	*cmd_path;

	error_catch(ast->cmd[0] == NULL, "empty command", root);

	// cmd_path = get_cmd_path(ast->cmd[0]);
	cmd_path = ft_strdup(ast->cmd[0]);

	if (cmd.cmd == 0)
	{
		free(cmd_path);
		error_catch(1, "problem with cmd or malloc fail", root);
	}
	ast->pid = fork();
	error_catch(ast->pid == -1, "fail to create fork", root);
	if (ast->pid == 0)
	{
		error_catch(dup2(fd_in, 0) == -1, "dup2 fail for fd_in", root);
		error_catch(dup2(fd_out, 1) == -1, "dup2 fail for fd_out", root);
		execve(cmd_path, ast->cmd, root->shell_env);
		free(cmd_path);
		error_catch(1, cmd_path, root);
		return (-1);
	}
	free(cmd_path);
	return (0);
}
