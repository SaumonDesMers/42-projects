#include "push_swap.h"

int	get_stack_checker(int ac, char **av, t_root *root)
{
	int		i;

	root->stack = NULL;
	root->stack_a = malloc(sizeof(int) * ac);
	root->stack_b = malloc(sizeof(int) * ac);
	if (!root->stack_a || !root->stack_b)
	{
		free_all(root);
		return (0);
	}
	root->size = ac - 1;
	root->size_a = root->size;
	root->size_b = 0;
	i = 0;
	while (++i < ac)
		root->stack_a[i - 1] = ft_atoi(av[i]);
	i = 0;
	while (i < root->size)
		root->stack_b[i++] = 0;
	return (1);
}

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
	free_all(root);
	return (0);
}