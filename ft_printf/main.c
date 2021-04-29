#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char	*format = "%-20x";
	int		value = 42;

	printf("(%d)\n", ft_printf(format, value));
	printf("(%d)\n", printf(format, value));
	return (0);
}