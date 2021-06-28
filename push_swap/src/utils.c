#include "push_swap.h"

int	get_min(int *tab, int size)
{
	int	i;
	int	min;

	min = tab[0];
	i = 0;
	while (i < size)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	free_all(t_root *root, int ret)
{
	free(root->stack_a);
	free(root->stack_b);
	free(root);
	return (ret);
}
