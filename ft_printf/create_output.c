#include "libft/libft.h"
#include "ft_printf.h"

void manage_specifier(t_list **output, char specifier, va_list ap)
{
	if (is_specifier(specifier, "di"))
	{
		ft_itol(output, va_arg(ap, int));
	}/*
	else if (specifier == 'u')
	{

	}
	else if (specifier == 'x')
	{

	}
	else if (specifier == 'X')
	{

	}
	else if (specifier == 'p')
	{

	}
	else if (specifier == 'c')
	{

	}
	else if (specifier == 's')
	{

	}*/
	else if (specifier == '%')
		*output = ft_lstnew(ft_strdup("%"));
}

void manage_precision(t_list **output, int precision, char specifier)
{
	int	nb;

	nb = 0;
	if (is_specifier(specifier, "diuxX"))
	{
		nb = ft_lstsize(*output);
		while (nb < precision)
		{
			ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
			nb++;
		}
	}
	if (is_specifier(specifier, "s"))
	{
		while (nb < precision && *output)
		{
			*output = (*output)->next;
			nb++;
		}
		ft_lstclear(output, &free);
	}
}

void manage_widht(t_list **output, char flag, int widht)
{
	int	nb;

	nb = ft_lstsize(*output);
	if (flag == '-')
	{
		while (nb++ < widht)
			ft_lstadd_back(output, ft_lstnew(ft_strdup(" ")));
	}
	else if (flag == '0')
	{
		while (nb++ < widht)
			ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
	}
	else
	{
		while (nb++ < widht)
			ft_lstadd_front(output, ft_lstnew(ft_strdup(" ")));
	}
}