#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *format = "%5%";
	printf("(%d)\n", ft_printf(format, 42));
	printf("(%d)\n", printf(format, 42));
	return (0);
}