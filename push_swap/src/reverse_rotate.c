#include "push_swap.h"

void	rra(t_root *root, int flag)
{
	int	tmp;
	int	i;

	if (root->size_a > 1)
	{
		i = root->size_a;
		tmp = root->stack_a[i - 1];
		while (--i > 0)
			root->stack_a[i] = root->stack_a[i - 1];
		root->stack_a[0] = tmp;
		if (flag)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_root *root, int flag)
{
	int	tmp;
	int	i;

	if (root->size_b > 1)
	{
		i = root->size_b;
		tmp = root->stack_b[i - 1];
		while (--i > 0)
			root->stack_b[i] = root->stack_b[i - 1];
		root->stack_b[0] = tmp;
		if (flag)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_root *root, int flag)
{
	rra(root, 0);
	rrb(root, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
