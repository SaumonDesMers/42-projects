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
	i = 0;
	while (++i < ac)
	{
		j = ft_atoi(av[i]);
		if (j > 2147483647 || j < -2147483648)
			return (0);
	}
	return (1);
}

int	*get_stack(int ac, char **av)
{
	int	*a;
	int	i;

	a = malloc(sizeof(int) * (ac - 1));
	if (!a)
		return (0);
	i = 0;
	while (++i < ac)
		a[i - 1] = ft_atoi(av[i]);
	return (a);
}