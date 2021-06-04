#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// void	*ptr = 0;

	printf("(%d)\n", ft_printf(0));
	printf("(%d)\n", printf(0));
	return (0);
}
