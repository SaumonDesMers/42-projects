#include "push_swap.h"

void	brutal_sorting(t_root *root)
{
	int	i;
	int	j;

	i = 0;
	while (i < root->size)
	{
		j = 0;
		while (j < root->size_a)
			if (root->stack_a[j++] == i)
				break ;
		if (j - 1 <= root->size_a / 2)
			while (j-- > 1)
				ra(root, 1);
		else
			while (j++ < root->size_a + 1)
				rra(root, 1);
		if (is_sorted(root->stack_a, root->size_a) == 1)
			break ;
		pb(root, 1);
		i++;
	}
	while (i--)
		pa(root, 1);
}

int	is_sorted(int *stack, int size)
{
	int	i;
	int	flag;

	if (size < 2)
		return (1);
	if (stack[0] < stack[1])
		flag = 1;
	else
		flag = -1;
	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] < stack[i + 1] && flag == -1)
			return (0);
		if (stack[i] > stack[i + 1] && flag == 1)
			return (0);
		i++;
	}
	return (flag);
}
