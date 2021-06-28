#include "push_swap.h"

void	sort_iterative(t_root *root)
{
	t_sample	sample;

	ft_bzero(sample.size_a, 64000 * sizeof(int));
	ft_bzero(sample.size_b, 64000 * sizeof(int));
	sample.size_a[0] = root->size_a;
	sample.nb_a = 1;
	sample.nb_b = 0;
	while (!is_sorted(root->stack_a, root->size_a) || root->size_b != 0)
	{
		if (sample.nb_a > 0 && sample.size_a[sample.nb_a - 1] > 3)
			push_lower_half_a_to_b(&sample, root);
		else
		{
			sort_sample(&sample, root);
			if (sample.nb_b > 0 && sample.size_b[sample.nb_b - 1] > 3)
				push_upper_half_b_to_a(&sample, root);
			else if (sample.nb_b > 0)
				push_sample_back_on_a(&sample, root);
		}
	}
}
