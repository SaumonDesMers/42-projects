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

void	rra(t_root *root, int flag)
{
	int	tmp;
	int	i;

	if (root->size_a > 1)
	{
		i = root->size_a;
		tmp = root->stack_a[i - 1];
		while (--i >= 0)
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
		while (--i >= 0)
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
