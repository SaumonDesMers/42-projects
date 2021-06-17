#include "push_swap.h"

void	sorting_size_3(t_root *root)
{
	if (wich_list(0, 2, 1, root))
	{
		rra(root, 1);
		sa(root, 1);
	}
	else if (wich_list(1, 0, 2, root))
		sa(root, 1);
	else if (wich_list(1, 2, 0, root))
		rra(root, 1);
	else if (wich_list(2, 1, 0, root))
	{
		sa(root, 1);
		rra(root, 1);
	}
	else if (wich_list(2, 0, 1, root))
		ra(root, 1);
}

int	wich_list(int n1, int n2, int n3, t_root *root)
{
	return (
		root->stack_a[0] == n1
		&& root->stack_a[1] == n2
		&& root->stack_a[2] == n3);
}
