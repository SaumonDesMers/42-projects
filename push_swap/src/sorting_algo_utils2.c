#include "push_swap.h"

static void	ra_sa_rra(t_root *root)
{
	ra(root, 1);
	sa(root, 1);
	rra(root, 1);
}

static void	ra_sa_rra_sa(t_root *root)
{
	ra(root, 1);
	sa(root, 1);
	rra(root, 1);
	sa(root, 1);
}

static void	sa_ra_sa_rra_sa(t_root *root)
{
	sa(root, 1);
	ra(root, 1);
	sa(root, 1);
	rra(root, 1);
	sa(root, 1);
}

static void	sa_ra_sa_rra(t_root *root)
{
	sa(root, 1);
	ra(root, 1);
	sa(root, 1);
	rra(root, 1);
}

void	sort_sample(t_sample *sample, t_root *root)
{
	int	first;
	int	second;
	int	third;

	if (sample->size_a[sample->nb_a - 1] == 2)
	{
		if (root->stack_a[0] > root->stack_a[1])
			sa(root, 1);
		return ;
	}
	first = root->stack_a[0];
	second = root->stack_a[1];
	third = root->stack_a[2];
	if (second > third && third > first)
		ra_sa_rra(root);
	else if (third > first && first > second)
		sa(root, 1);
	else if (second > first && first > third)
		ra_sa_rra_sa(root);
	else if (first > second && second > third)
		sa_ra_sa_rra_sa(root);
	else if (first > third && third > second)
		sa_ra_sa_rra(root);
}
