#include "pipex.h"

int	main(int ac, char **av)
{
	t_root	root;

	root.nb_cmd = count_cmd(ac, av, &root);
	error_catch(root.nb_cmd == -1, "not enough argument", &root);
	open_and_malloc(ac, av, &root);
	heredoc_or_not(av, &root);
	while (wait(NULL) != -1)
		;
	free_root(&root);
	return (0);
}
