#include "push_swap.h"

void	push_sample_back_on_a(t_sample *sample, t_root *root)
{
	int	size_sample;
	int	i;

	size_sample = sample->size_b[sample->nb_b - 1];
	i = 0;
	while (i < size_sample)
	{
		pa(root, 1);
		i++;
	}
	sample->nb_a++;
	sample->size_b[sample->nb_b - 1] = 0;
	sample->nb_b--;
	sample->size_a[sample->nb_a - 1] = size_sample;
}

void	push_lower_half_a_to_b(t_sample *sample, t_root *root)
{
	int	size_sample;
	int	median;
	int	i;
	int	j;

	size_sample = sample->size_a[sample->nb_a - 1];
	median = get_median(root->stack_a, size_sample);
	i = 0;
	j = 0;
	while (i < size_sample)
	{
		if (root->stack_a[0] < median)
			pb(root, 1);
		else
		{
			ra(root, 1);
			j++;
		}
		i++;
	}
	while (j-- && sample->nb_a > 1)
		rra(root, 1);
	sample->nb_b++;
	sample->size_b[sample->nb_b - 1] = size_sample / 2;
	sample->size_a[sample->nb_a - 1] -= size_sample / 2;
}

void	push_upper_half_b_to_a(t_sample *sample, t_root *root)
{
	int	size_sample;
	int	median;
	int	i;
	int	j;

	size_sample = sample->size_b[sample->nb_b - 1];
	median = get_median(root->stack_b, size_sample);
	i = 0;
	j = 0;
	while (i < size_sample)
	{
		if (root->stack_b[0] >= median)
			pa(root, 1);
		else
		{
			rb(root, 1);
			j++;
		}
		i++;
	}
	while (j-- && sample->nb_b > 1)
		rrb(root, 1);
	sample->nb_a++;
	sample->size_a[sample->nb_a - 1] = (size_sample + 1) / 2;
	sample->size_b[sample->nb_b - 1] -= (size_sample + 1) / 2;
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
