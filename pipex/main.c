#include "pipex.h"

int	main(int ac, char **av)
{
	int		nb_cmd;
	int		*pid;
	int		*fd_pipe[2];
	int		fd_input;
	int		fd_output;
	int		i;

	nb_cmd = count_cmd(ac);
	error_catch(nb_cmd, -1, "Error : not enough argument");

	fd_input = open(av[1], O_RDONLY);
	error_catch(fd_input, -1, "Error : fail to open input file");

	if (access(av[ac - 1], F_OK) == -1)
		fd_output = open(av[ac - 1], O_CREAT | O_WRONLY);
	else
		fd_output = open(av[ac - 1], O_WRONLY);
	error_catch(fd_output, -1, "Error : fail to open output file");

	pid = malloc(sizeof(int) * nb_cmd);
	error_catch((int)pid, 0, "Error : fail to malloc pid list");

	*fd_pipe = malloc(sizeof(int[2]) * (nb_cmd + 1));
	error_catch((int)pid, 0, "Error : fail to malloc pipe list");


	// error_catch(dup2(), -1, "Error : fail from dup2");

	i = 0;
	while (i < nb_cmd)
	{
		exec_cmd(av[i + 2]);
		i++;
	}
	while (wait(NULL) != -1);
	free(pid);
	free(*fd_pipe);
	close(fd_input);
	close(fd_output);
	return (0);
}
