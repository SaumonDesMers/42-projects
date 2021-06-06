#include "push_swap.h"

int	main(int ac, char **av)
{
	t_root	*root;
	// int		i;
	// void	(*f[100])(t_root *, int) = {rra,
	// 									pb,
	// 									pb,
	// 									rr,
	// 									NULL};

	if (!check_arg(ac, av))
	{
		printf("Error arg\n");
		return (0);
	}
	root = malloc(sizeof(t_root));
	if (!root)
		return (0);
	if (!get_stack(ac, av, root))
		return (0);

	// i = 0;
	// while (f[i])
	// 	f[i++](root, 1);

	brutal_sorting(root);

	// i = 0;
	// while (i < ac - 1)
	// {
	// 	printf("%d\t[%2d] [%2d]\n", root->stack[i], root->stack_a[i], root->stack_b[i]);
	// 	i++;
	// }
	free_all(root);
	return (0);
}