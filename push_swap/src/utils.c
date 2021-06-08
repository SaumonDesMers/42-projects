#include "push_swap.h"

void	free_all(t_root *root)
{
	free(root->stack);
	free(root);
}
