#include "push_swap.h"

int	main(int ac, char **av)
{
	t_root	*root;

	if (!check_arg(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	root = malloc(sizeof(t_root));
	if (!root)
		return (0);
	if (!get_stack(ac, av, root))
		return (0);
	if (root->size_a == 3)
		sorting_size_three(root);
	if (root->size_a == 5)
		sorting_size_five(root);
	else
		sort_iterative(root);
	free_all(root, 0);
	return (0);
}
