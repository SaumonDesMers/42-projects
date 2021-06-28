#include "push_swap.h"

void	sorting_size_three(t_root *root)
{
	if (wich_list("021", root->stack_a, 3))
	{
		rra(root, 1);
		sa(root, 1);
	}
	else if (wich_list("102", root->stack_a, 3))
		sa(root, 1);
	else if (wich_list("120", root->stack_a, 3))
		rra(root, 1);
	else if (wich_list("210", root->stack_a, 3))
	{
		sa(root, 1);
		rra(root, 1);
	}
	else if (wich_list("201", root->stack_a, 3))
		ra(root, 1);
}

int	wich_list(char *list, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] != list[i] - '0')
			return (0);
		i++;
	}
	return (1);
}
