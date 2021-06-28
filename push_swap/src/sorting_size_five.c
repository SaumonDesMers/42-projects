#include "push_swap.h"

static void	push_lower_half_a_to_b_for_five(int size_sample, t_root *root)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size_sample)
	{
		if (root->stack_a[0] < 2)
		{
			pb(root, 1);
			if (++j >= 2)
				return ;
		}
		else
			ra(root, 1);
		i++;
	}
}

static void	sorting_size_three_for_five(t_root *root)
{
	if (wich_list("243", root->stack_a, 3))
	{
		rra(root, 1);
		sa(root, 1);
	}
	else if (wich_list("324", root->stack_a, 3))
		sa(root, 1);
	else if (wich_list("342", root->stack_a, 3))
		rra(root, 1);
	else if (wich_list("432", root->stack_a, 3))
	{
		sa(root, 1);
		rra(root, 1);
	}
	else if (wich_list("423", root->stack_a, 3))
		ra(root, 1);
}

void	sorting_size_five(t_root *root)
{
	push_lower_half_a_to_b_for_five(5, root);
	sorting_size_three_for_five(root);
	pa(root, 1);
	pa(root, 1);
	if (root->stack_a[0] > root->stack_a[1])
		sa(root, 1);
}
