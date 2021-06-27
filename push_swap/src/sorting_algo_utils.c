#include "push_swap.h"

void	push_sample_back_on_a(t_sample *sample, t_root *root)
{
	int	size_sample;
	int	i;

	size_sample = sample->size_b[sample->nb_b - 1];
	i = 0;
	while (i < size_sample)
	{
		pa(root, 0);
		i++;
	}
	sample->nb_a++;
	sample->size_b[sample->nb_b - 1] = 0;
	sample->nb_b--;
	sample->size_a[sample->nb_a - 1] = size_sample;
}

void	push_lower_half_a_to_b(t_sample *sample, t_root *root)
{
	int	size_sample = sample->size_a[sample->nb_a - 1];
	int	median;
	int	i;
	int	j;

	median = get_median(root->stack_a, size_sample);
	i = 0;
	j = 0;
	while (i < size_sample)
	{
		if (root->stack_a[0] < median)
		{
			pb(root, 0);
			// if (++i > size_sample / 2)
			// 	break ;
		}
		else
		{
			ra(root, 0);
			j++;
		}
		i++;
	}
	while (j--)
		rra(root, 0);
	sample->nb_b++;
	sample->size_b[sample->nb_b - 1] = size_sample / 2;
	sample->size_a[sample->nb_a - 1] -= size_sample / 2;
}

void	push_upper_half_b_to_a(t_sample *sample, t_root *root)
{
	int	size_sample = sample->size_b[sample->nb_b - 1];
	int	median;
	int	i;
	int	j;

	median = get_median(root->stack_b, size_sample);
	i = 0;
	j = 0;
	while ( i < size_sample)
	{
		if (root->stack_b[0] > median)
		{
			pa(root, 0);
			// if (++i > size_sample / 2)
			// 	break ;
		}
		else
		{
			rb(root, 0);
			j++;
		}
		i++;
	}
	while (j--)
		rrb(root, 0);
	sample->nb_a++;
	sample->size_a[sample->nb_a - 1] = size_sample / 2;
	sample->size_b[sample->nb_b - 1] -= size_sample / 2;
}

void	sort_sample(t_sample *sample, t_root *root)
{
	int	first;
	int	second;
	int	third;

	if (sample->size_a[sample->nb_a - 1] == 2)
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
