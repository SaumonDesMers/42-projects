#include "pipex.h"

int	main(int ac, char **av)
{
	t_root	root;

	root.nb_cmd = count_cmd(ac, av, &root);
	if (root.nb_cmd == -1)
	{
		write(2, "Error : not enough argument\n", 28);
		return (0);
	}
	check_input(av, &root);
	open_and_malloc(ac, av, &root);
	heredoc_or_not(av, &root);
	while (wait(NULL) != -1)
		;
	free_root(&root);
	return (0);
}
