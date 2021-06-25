#include "push_swap.h"

void	sort(int size_sample, t_root *root)
{
	push_lower_half_a_to_b(size_sample, root);
	size_sample = (size_sample + 1) / 2;
	if (size_sample > 3)
		sort(size_sample, root);
	else
	{
		sort_sample(size_sample, root);
	}
	if (size_sample <= 3)
	{
		push_sample_back_on_a(size_sample, root);
		sort_sample(size_sample, root);
	}
	else
	{
		push_upper_half_b_to_a(size_sample, root);
		if (size_sample > 3)
			sort(size_sample, root);
	}
}
