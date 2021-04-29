#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	manage_specifier(t_list **output, int *tag, va_list ap)
{
	long long value;
	
	if (is_specifier(tag[3], "diuxX"))
	{
		value = va_arg(ap, int);
		if (value != 0 || tag[2] != 0)
			case_diuxX(output, tag[3], value);
	}
	/*
	else if (specifier == 'p')
	{

	}
	else if (specifier == 'c')
	{

	}
	else if (specifier == 's')
	{

	}*/
	else if (tag[3] == '%')
		*output = ft_lstnew(ft_strdup("%"));
}

void	case_diuxX(t_list **output, char specifier, long long value)
{
	if (is_specifier(specifier, "diu"))
	{
		if (specifier == 'u' && value < 0)
			ft_itol(output, value + 4294967296, "0123456789");
		else
			ft_itol(output, value, "0123456789");
	}
	else if (specifier == 'x')
	{
		if (value < 0)
			ft_itol(output, value  + 4294967296, "0123456789abcdef");
		else
			ft_itol(output, value, "0123456789abcdef");
	}
	else if (specifier == 'X')
	{
		if (value < 0)
			ft_itol(output, value  + 4294967296, "0123456789ABCDEF");
		else
			ft_itol(output, value, "0123456789ABCDEF");
	}
}

void	manage_precision(t_list **output, int *tag)
{
	int	nb;

	nb = 0;
	if (is_specifier(tag[3], "diuxX"))
	{
		nb = ft_lstsize(*output);
		if (!ft_strncmp((*output)->content, "-", 1))
			while (nb++ < tag[2])
				ft_lstadd_front(&(*output)->next, ft_lstnew(ft_strdup("0")));
		else
			while (nb++ < tag[2] - 1)
				ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
	}
	if (is_specifier(tag[3], "s"))
	{
		while (nb < tag[2] && *output)
		{
			*output = (*output)->next;
			nb++;
		}
		ft_lstclear(output, &free);
	}
}

void	manage_widht(t_list **output, int *tag)
{
	int	nb;

	nb = ft_lstsize(*output);
	if (tag[0] == '-')
	{
		while (nb++ < tag[1])
			ft_lstadd_back(output, ft_lstnew(ft_strdup(" ")));
	}
	else if (tag[0] == '0')
	{
		if (!ft_strncmp((*output)->content, "-", 1))
			while (nb++ < tag[1])
				ft_lstadd_front(&(*output)->next, ft_lstnew(ft_strdup("0")));
		else
			while (nb++ < tag[1])
				ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
	}
	else
	{
		while (nb++ < tag[1])
			ft_lstadd_front(output, ft_lstnew(ft_strdup(" ")));
	}
}