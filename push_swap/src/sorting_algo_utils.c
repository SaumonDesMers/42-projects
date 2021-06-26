#include "push_swap.h"

void	push_sample_back_on_a(int size_sample, t_root *root)
{
	int	i;

	i = 0;
	while (i < size_sample)
	{
		pa(root, 0);
		i++;
	}
}

void	sort_sample(int size_sample, t_root *root)
{
	int	first;
	int	second;
	int	third;

	if (size_sample == 2)
	{
		if (root->stack_a[0] > root->stack_a[1])
			sa(root, 0);
		return ;
	}
	first = root->stack_a[0];
	second = root->stack_a[1];
	third = root->stack_a[2];
	if (second > third && third > first)
	{
		ra(root, 0);
		sa(root, 0);
		rra(root, 0);
	}
	else if (third > first && first > second)
		sa(root, 0);
	else if (second > first && first > third)
	{
		ra(root, 0);
		sa(root, 0);
		rra(root, 0);
		sa(root, 0);
	}
	else if (first > second && second > third)
	{
		sa(root, 0);
		ra(root, 0);
		sa(root, 0);
		rra(root, 0);
		sa(root, 0);
	}
	else if (first > third && third > second)
	{
		sa(root, 0);
		ra(root, 0);
		sa(root, 0);
		rra(root, 0);
	}
}

t_bool	lower_value_to_push(int *stack, int median, int size_sample)
{
	int	i;

	i = 0;
	while (i < size_sample)
	{
		if (stack[i++] < median)
			return (1);
	}
	return (0);
}

t_bool	upper_value_to_push(int *stack, int median, int size_sample)
{
	int	i;

	i = 0;
	while (i < size_sample)
	{
		if (stack[i++] > median)
			return (1);
	}
	return (0);
}

void	push_lower_half_a_to_b(int size_sample, t_root *root)
{
	int	median;
	int	i;
	int	j;

	median = get_median(root->stack_a, size_sample);
	i = 0;
	j = 0;
	while (size_sample--)
	{
		// if (!lower_value_to_push(root->stack_a, median, size_sample + 1))
		// 	break ;
		if (root->stack_a[0] < median)
			pb(root, 0);
		else
		{
			ra(root, 0);
			j++;
		}
	}
	while (j--)
		rra(root, 0);
}

void	push_upper_half_b_to_a(int size_sample, t_root *root)
{
	int	median;
	int	i;
	int	j;

	median = get_median(root->stack_b, size_sample);
	i = 0;
	j = 0;
	while (size_sample--)
	{
		// if (!upper_value_to_push(root->stack_b, median, size_sample + 1))
		// 	break ;
		if (root->stack_b[0] >= median)
			pa(root, 0);
		else
		{
			rb(root, 0);
			j++;
		}
	}
	while (j--)
		rrb(root, 0);
}

int	get_median(int *stack, int size)
{
	int	min;
	int	i;

	min = stack[0];
	i = 0;
	while (i < size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min + (size / 2));
}
