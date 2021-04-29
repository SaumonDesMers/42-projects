#include "libft/libft.h"
#include "ft_printf.h"

char	ft_specifier(char *tags)
{
	while (*(tags + 1))
		tags++;
	return (*tags);
}

char	ft_flag(char *tags, int *tag, int is_precision_define)
{
	if (tags[0] == '-' || tags[1] == '-')
		return ('-');
	if (is_specifier(tag[3], "cs"));
		return (0);
	if (tags[0] == '0' && (!is_precision_define || (is_precision_define && tag[2] < 0)))
		return ('0');
	return (0);
}

int		ft_widht(char *tags, va_list ap)
{
	int		widht;
	int		i;

	widht = 0;
	i = 0;
	while (tags[i] == '-' || tags[i] == '0')
		i++;
	if (tags[i] == '*')
	{
		widht = va_arg(ap, int);
		if (widht < 0)
			widht = -widht;
		return (widht);
	}
	while (tags[i] != '.' && !is_specifier(tags[i], "cspdiuxX%%"))
		widht = widht * 10 + tags[i++] - 48;
	return (widht);
}

int		ft_precision(char *tags, va_list ap, int *is_precision_define)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	while (tags[i] != '.' && !is_specifier(tags[i], "cspdiuxX%%"))
		i++;
	if (is_specifier(tags[i], "s"))
		return (-1);
	if (is_specifier(tags[i], "cspdiuxX%%"))
		return (1);
	*is_precision_define = 1;
	if (tags[i] == '.' && tags[i + 1] == '*')
		return (va_arg(ap, int));
	if (tags[i] == '.')
		i++;
	while (!is_specifier(tags[i], "cspdiuxX%%"))
		precision = precision * 10 + tags[i++] - 48;
	return (precision);
}