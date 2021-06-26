#include "push_swap.h"

void	sort(int size_sample, t_root *root)
{
	// 	push_lower_half_a_to_b(20, root);
	// 		push_lower_half_a_to_b(10, root);
	// 			push_lower_half_a_to_b(5, root);
	// 				sort_sample(3, root);
	// 			push_sample_back_on_a(2, root);
	// 			sort_sample(2, root);
	// 		push_upper_half_b_to_a(5, root);
	// 			sort_sample(3, root);
	// 		push_sample_back_on_a(2, root);
	// 		sort_sample(2, root);
	// 	push_upper_half_b_to_a(10, root);
	// 		push_lower_half_a_to_b(5, root);
	// 			sort_sample(3, root);
	// 		push_sample_back_on_a(2, root);
	// 		sort_sample(2, root);
	// 	push_upper_half_b_to_a(5, root);
	// 		sort_sample(3, root);
	// 	push_sample_back_on_a(2, root);
	// 	sort_sample(2, root);
	// ;
	
	int	next_size_sample;

	if (size_sample > 3)
	{
		printf("push_lower_half_a_to_b : size_sample = %d\n", size_sample);
		push_lower_half_a_to_b(size_sample, root);
		print_stacks(root);
		next_size_sample = (size_sample + 1) / 2;
		sort(next_size_sample, root);
		size_sample -= next_size_sample;
	}
	else
	{
		printf("sort_sample : size_sample = %d\n", size_sample);
		sort_sample(size_sample, root);
		print_stacks(root);
		return ;
	}
	if (size_sample <= 3)
	{
		printf("1 push_sample_back_on_a & sort_sample : size_sample = %d\n", size_sample);
		push_sample_back_on_a(size_sample, root);
		sort_sample(size_sample, root);
		print_stacks(root);
	}
	else
	{
		printf("push_upper_half_b_to_a : size_sample = %d\n", size_sample);
		push_upper_half_b_to_a(size_sample, root);
		print_stacks(root);
		next_size_sample = (size_sample + 1) / 2;
		sort(next_size_sample, root);
		size_sample -= next_size_sample;
		printf("2 push_sample_back_on_a & sort_sample : size_sample = %d\n", size_sample);
		push_sample_back_on_a(size_sample, root);
		sort_sample(size_sample, root);
		print_stacks(root);
	}
}
