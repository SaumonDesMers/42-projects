#include "pipex.h"

int	main(int ac, char **av)
{
	int		nb_cmd;
	t_root	root;
	int		i;
	int		testfd[2];

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
		root.fd_output = open(av[ac - 1], O_WRONLY | O_TRUNC);
	error_catch(root.fd_output == -1, "fail to open output file", &root);

	root.pid = malloc(sizeof(int) * nb_cmd);
	error_catch(root.pid == 0, "fail to malloc pid list", &root);

	i = 0;
	while (i < nb_cmd)
	{
		root.fd_pipe[i] = malloc(sizeof(int[2]));
		error_catch(root.fd_pipe[i++] == 0, "fail to malloc pipe list", &root);
	}

	i = 0;
	while (i < nb_cmd)
		error_catch(pipe(root.fd_pipe[i++]) == -1, "fail to open pipe", &root);

	pipe(testfd);

	if (nb_cmd == 1)
		exec_cmd(av[2], root.fd_input, root.fd_output, &root);
	else
	{
		exec_cmd(av[2], root.fd_input, testfd[1], &root);
		printf("b\n");
		i = 1;
		// while (i < nb_cmd - 1)
		// {
		// 	exec_cmd(av[i + 2], root.fd_pipe[i - 1][0], root.fd_pipe[i][1], &root);
		// 	printf("c\n");
		// 	i++;
		// }
		exec_cmd(av[3], testfd[0], root.fd_output, &root);
		printf("d\n");
	}
	
	
	while (wait(NULL) != -1);
	free_root(&root);
	return (0);
}
