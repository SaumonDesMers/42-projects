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
	j = 0;
	while (++i < ac)
	{
		nb = ft_atol(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
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

	root->stack_a = malloc(sizeof(int) * ac);
	root->stack_b = malloc(sizeof(int) * ac);
	if (!root->stack_a || !root->stack_b)
		return (free_all(root, 0));
	root->size_a = ac - 1;
	root->size_b = 0;
	i = 0;
	while (++i < ac)
	{
		root->stack_a[i - 1] = 0;
		j = 1;
		while (j < ac)
			if (ft_atoi(av[i]) > ft_atoi(av[j++]))
				root->stack_a[i - 1]++;
	}
	i = 0;
	while (i < ac - 1)
		root->stack_b[i++] = -1;
	return (1);
}
