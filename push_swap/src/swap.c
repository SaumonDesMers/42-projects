#include "push_swap.h"

void	sa(t_root *root, int flag)
{
	int	tmp;

	if (root->size_a >= 2)
	{
		tmp = root->stack_a[0];
		root->stack_a[0] = root->stack_a[1];
		root->stack_a[1] = tmp;
		if (flag)
			write(1, "sa\n", 3);
	}
}

void	sb(t_root *root, int flag)
{
	int	tmp;

	if (root->size_b >= 2)
	{
		tmp = root->stack_b[0];
		root->stack_b[0] = root->stack_b[1];
		root->stack_b[1] = tmp;
		if (flag)
			write(1, "sb\n", 3);
	}
}

void	ss(t_root *root, int flag)
{
	sa(root, 0);
	sb(root, 0);
	if (flag)
		write(1, "ss\n", 3);
}
