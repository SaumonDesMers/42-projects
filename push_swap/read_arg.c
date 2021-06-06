#include "push_swap.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (0);
		}
	}
	// i = 0;
	// while (++i < ac)
	// {
	// 	j = ft_atoi(av[i]);
	// 	if (j > 2147483647 || j < -2147483648)
	// 		return (0);
	// }
	return (1);
}

int	get_stack(int ac, char **av, t_root *root)
{
	int		i;

	root->stack_a = malloc(sizeof(t_value) * ac);
	if (!root->stack_a)
		return (0);
	root->stack_b = NULL;
	i = 0;
	while (++i < ac)
		(root->stack_a + i)->value = ft_atoi(av[i]);
	return (1);
}