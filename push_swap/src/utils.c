#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;
	int	flag;

	if (size < 2)
		return (1);
	if (stack[0] < stack[1])
		flag = 1;
	else
		flag = -1;
	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] < stack[i + 1] && flag == -1)
			return (0);
		if (stack[i] > stack[i + 1] && flag == 1)
			return (0);
		i++;
	}
	return (flag);
}

int	free_all(t_root *root, int ret)
{
	free(root->stack_a);
	free(root->stack_b);
	free(root);
	return (ret);
}
