#include "push_swap.h"

void	free_all(t_root *root)
{
	free(root->stack_a);
	free(root);
}

int	main(int ac, char **av)
{
	t_root	*root;
	int		i;

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
	i = 0;
	while (++i < ac)
		printf("%d\n", (root->stack_a + i)->value);
	free_all(root);
	return (0);
}