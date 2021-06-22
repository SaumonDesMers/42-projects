#include "pipex.h"

int	main(int ac, char **av)
{
	int		nb_cmd;
	t_root	root;
	int		i;

	root.pid = 0;
	*root.fd_pipe = 0;
	root.fd_input = -1;
	root.fd_output = -1;

	nb_cmd = count_cmd(ac);
	error_catch(nb_cmd == -1, "not enough argument", &root);

	root.fd_input = open(av[1], O_RDONLY);
	error_catch(root.fd_input == -1, "fail to open input file", &root);

	if (access(av[ac - 1], F_OK) == -1)
		root.fd_output = open(av[ac - 1], O_CREAT | O_WRONLY);
	else
		root.fd_output = open(av[ac - 1], O_WRONLY);
	error_catch(root.fd_output == -1, "fail to open output file", &root);

	root.pid = malloc(sizeof(int) * nb_cmd);
	error_catch(root.pid == 0, "fail to malloc pid list", &root);

	*(root.fd_pipe) = malloc(sizeof(int[2]) * (nb_cmd + 1));
	error_catch(root.fd_pipe == 0, "fail to malloc pipe list", &root);

	// error_catch(dup2(), -1, "fail from dup2", &root);

	i = 0;
	while (i < nb_cmd)
	{
		exec_cmd(av[i + 2], &root);
		i++;
	}
	while (wait(NULL) != -1);
	free_all(&root);
	return (0);
}
