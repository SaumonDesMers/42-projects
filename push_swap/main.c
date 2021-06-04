#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*a;
	int	size;
	int	i;

	if (!check_arg(ac, av))
	{
		printf("Error arg\n");
		return (0);
	}
	a = get_stack(ac, av);
	size = ac - 1;
	i = 0;
	while (i < size)
		printf("%d\n", a[i++]);
	free(a);
	return (0);
}