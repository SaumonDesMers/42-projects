#include "push_swap.h"

int	main(int ac, char **av)
{
	t_root	*root;

	if (!check_arg(ac, av))
	{
		printf("Error arg\n");
		return (0);
	}
	root = malloc(sizeof(t_root));
	if (!root)
		return (0);
	if (!get_stack_checker(ac, av, root))
		return (0);

	sort_stack(root);
	
	free_all(root);
	return (0);
}