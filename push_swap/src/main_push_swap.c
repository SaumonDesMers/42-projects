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
		sorting_size_3(root);
	else
	{
		sort(root->size_a, root);
		// brutal_sorting(root);
	}
	printf("{%d}  {%d}\n", root->size_a, root->size_b);
	int i = 0;
	while (i < root->size_a + root->size_b)
	{
		printf("[%d]  [%d]\n", root->stack_a[i], root->stack_b[i]);
		i++;
	}
	free_all(root, 0);
	return (0);
}
