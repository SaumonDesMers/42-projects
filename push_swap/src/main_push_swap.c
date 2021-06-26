#include "push_swap.h"

void	print_stacks(t_root *root)
{
	// getchar();
	printf("{%d}\t{%d}\n", root->size_a, root->size_b);
	int i = 0;
	while (i < root->size_a + root->size_b)
	{
		printf("[%.d]\t[%.d]\n", root->stack_a[i] + 1, root->stack_b[i] + 1);
		i++;
	}
}

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
	
	// print_stacks(root);
	if (root->size_a == 3)
		sorting_size_3(root);
	else
	{
		// sort(root->size_a, root);
		brutal_sorting(root);
	}
	// print_stacks(root);
	free_all(root, 0);
	return (0);
}
