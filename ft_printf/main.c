#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *str = 0;
	printf("(%d)\n", ft_printf("%s", str));
	printf("(%d)\n", printf("%s", str));
	return (0);
}