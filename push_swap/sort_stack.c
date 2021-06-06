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
		pb(root, 1);
		i++;
	}
	while (i--)
		pa(root, 1);
}
