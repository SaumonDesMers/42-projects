#include "push_swap.h"

void	pa(t_root *root, int flag)
{
	int	i;

	if (root->size_b > 0)
	{
		i = root->size_a;
		while (i >= 0)
		{
			root->stack_a[i + 1] = root->stack_a[i];
			i--;
		}
		root->stack_a[0] = root->stack_b[0];
		i = 0;
		while (i + 1 < root->size_b)
		{
			root->stack_b[i] = root->stack_b[i + 1];
			i++;
		}
		root->stack_b[i] = -1;
		root->size_a++;
		root->size_b--;
		if (flag)
			write(1, "pa\n", 3);
	}
}

void	pb(t_root *root, int flag)
{
	int	i;

	if (root->size_a > 0)
	{
		i = root->size_b;
		while (i >= 0)
		{
			root->stack_b[i + 1] = root->stack_b[i];
			i--;
		}
		root->stack_b[0] = root->stack_a[0];
		i = 0;
		while (i + 1 < root->size_a)
		{
			root->stack_a[i] = root->stack_a[i + 1];
			i++;
		}
		root->stack_a[i] = -1;
		root->size_b++;
		root->size_a--;
		if (flag)
			write(1, "pb\n", 3);
	}
}
