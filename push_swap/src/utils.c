#include "push_swap.h"

int	free_all(t_root *root, int ret)
{
	free(root->stack_a);
	free(root->stack_b);
	free(root);
	return (ret);
}
