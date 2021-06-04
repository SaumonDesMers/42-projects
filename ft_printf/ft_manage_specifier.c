#include "libft/libft.h"
#include "ft_printf.h"

int	manage_specifier(t_list **output, int *tag, va_list ap)
{
	long long		value;
	char			c[2];

	if (is_specifier(tag[3], "diuxX"))
	{
		value = va_arg(ap, int);
		if (value != 0 || tag[2] != 0)
			if (!case_diuxX(output, tag[3], value))
				return (0);
	}
	else if (tag[3] == 'c')
	{
		c[0] = (unsigned char)va_arg(ap, int);
		c[1] = 0;
		*output = ft_lstnew(ft_strdup(c));
		if (!*output)
			return (0);
	}
	else
		if (!manage_specifier_2(output, tag, ap))
			return (0);
	return (1);
}

int	manage_specifier_2(t_list **output, int *tag, va_list ap)
{
	unsigned long	ptr;

	if (tag[3] == 's')
	{
		if (!ft_stol(output, va_arg(ap, char *)))
			return (0);
	}
	else if (tag[3] == 'p')
	{
		ptr = va_arg(ap, unsigned long);
		if (!ft_ultol(output, ptr, "0123456789abcdef"))
			return (0);
	}
	else if (tag[3] == '%')
	{
		*output = ft_lstnew(ft_strdup("%"));
		if (!*output)
			return (0);
	}
	return (1);
}
