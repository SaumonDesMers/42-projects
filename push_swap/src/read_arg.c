#include "push_swap.h"

int	check_arg(int ac, char **av)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
				return (0);
	}
	i = 0;
	while (++i < ac)
	{
		nb = ft_atol(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
	}
	i = 0;
	j = 0;
	while (++i < ac)
	{
		nb = ft_atol(av[i]);
		j = i;
		while (++j < ac)
			if (nb == ft_atol(av[j]))
				return (0);
	}
	return (1);
}

int	get_stack(int ac, char **av, t_root *root)
{
	int		i;
	int		j;
	int		index;

	root->stack = malloc(sizeof(int) * ac);
	root->stack_a = malloc(sizeof(int) * ac);
	root->stack_b = malloc(sizeof(int) * ac);
	if (!root->stack || !root->stack_a || !root->stack_b)
	{
		free_all(root);
		return (0);
	}
	root->size = ac - 1;
	root->size_a = root->size;
	root->size_b = 0;
	i = 0;
	while (++i < ac)
		root->stack[i - 1] = ft_atoi(av[i]);
	i = 0;
	while (i < root->size)
	{
		index = 0;
		j = 0;
		while (j < root->size)
			if (root->stack[i] > root->stack[j++])
				index++;
		root->stack_a[i++] = index;
	}
	i = 0;
	while (i < root->size)
		root->stack_b[i++] = -1;
	return (1);
}