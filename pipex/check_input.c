#include "pipex.h"

void	check_input(char **av, t_root *root)
{
	int		i;
	char	*cmd;

	i = 1;
	while (i - 1 < root->nb_cmd)
	{
		cmd = get_path(av[1 + i + root->here_doc]);
		if (cmd == NULL)
		{
			write(2, "Error : cmd not found\n", 22);
			exit(0);
		}
		free(cmd);
		i++;
	}
}
