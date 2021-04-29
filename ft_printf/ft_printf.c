#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nbchar;
	char	*tags;

	i = 0;
	nbchar = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			tags = take_tags((char*)(format + i + 1));
			//printf("[");
			nbchar += pars_tags(tags, ap);
			//printf("]");
			i += ft_strlen(tags) + 1;
			free(tags);
		}
		else
		{
			//printf("%c", format[i++]);
			write(1, &format[i++], 1);
			nbchar++;
		}
	}
	va_end(ap);
	return (nbchar);
}

/*

%[flags][width][.precision][length]specifier

[flags] :
- = Left-justify within the given field width
0 = Left-pads the number with zeroes (0) instead of spaces

[width]
(number) = Minimum number of characters to be printed
* = take (number) in argument

[.precision]
(.number) = Minimum number of digits to be printed if specifier is (d, i, u, x, X)
(.number) = Maximum number of character to be printed if specifier is (s)
.* = take (.number) in argument

[specifier] :
c = un character non signe
s = une string
p = une adresse en hexa
d = un entier décimal
i = un entier décimal
u = un entier decimal non signe
x = un entier en hexa(minuscule)
X = un entier en hexa(majuscule)
% = écrire '%'

*/