#include "push_swap.h"

void	ra(t_root *root, int flag)
{
	int	tmp;
	int	i;

	if (root->size_a > 1)
	{
		i = 0;
		tmp = root->stack_a[0];
		while (i + 1 < root->size_a)
		{
			root->stack_a[i] = root->stack_a[i + 1];
			i++;
		}
		root->stack_a[i] = tmp;
		if (flag)
			write(1, "ra\n", 3);
	}
}

void	rb(t_root *root, int flag)
{
	int	tmp;
	int	i;

	if (root->size_b > 1)
	{
		i = 0;
		tmp = root->stack_b[0];
		while (i + 1 < root->size_b)
		{
			root->stack_b[i] = root->stack_b[i + 1];
			i++;
		}
		root->stack_b[i] = tmp;
		if (flag)
			write(1, "rb\n", 3);
	}
}

void	rr(t_root *root, int flag)
{
	ra(root, 0);
	rb(root, 0);
	if (flag)
		write(1, "rr\n", 3);
}
