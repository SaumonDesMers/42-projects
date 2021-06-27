#include "push_swap.h"

void	sort_iterative(t_root *root)
{
	t_sample	sample;

	ft_bzero(sample.size_a, 100 * sizeof(int));
	ft_bzero(sample.size_b, 100 * sizeof(int));
	sample.size_a[0] = root->size_a;
	sample.nb_a = 1;
	sample.nb_b = 0;

	while (!is_sorted(root->stack_a, root->size_a) || root->size_b != 0)
	{
		print_stacks(root);
		printf("{%d %d} {%d %d}\n", sample.size_a[sample.nb_a - 1], sample.nb_a, sample.size_b[sample.nb_b - 1], sample.nb_b);
		if (sample.size_a[sample.nb_a -1] > 3)
		{
			printf("a\n");
			push_lower_half_a_to_b(&sample, root);
		}
		else
		{
			sort_sample(&sample, root);
			if (sample.size_b[sample.nb_b -1] > 3)
			{
				printf("b\n");
				push_upper_half_b_to_a(&sample, root);
			}
			else
			{
				printf("c\n");
				push_sample_back_on_a(&sample, root);
			}
		}
		
	}
}