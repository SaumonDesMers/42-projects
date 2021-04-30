#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	manage_specifier(t_list **output, int *tag, va_list ap)
{
	long long		value;
	unsigned long	ptr;
	char			c[2];
	
	if (is_specifier(tag[3], "diuxX"))
	{
		value = va_arg(ap, int);
		if (value != 0 || tag[2] != 0)
			case_diuxX(output, tag[3], value);
	}
	else if (tag[3] == 'c')
	{
		c[0] = (unsigned char)va_arg(ap, int);
		c[1] = 0;
		*output = ft_lstnew(ft_strdup(c));
	}
	else if (tag[3] == 's')
		ft_stol(output, va_arg(ap, char*));
	else if (tag[3] == 'p')
	{
		ptr = va_arg(ap, unsigned long);
		ft_ultol(output, ptr, "0123456789abcdef");
	}
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
	else if (is_specifier(specifier, "x"))
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

void	manage_precision(t_list **output, int *tag, int is_precision_define)
{
	int		nb;
	t_list	*copy;

	nb = 0;
	copy = *output;
	if (is_specifier(tag[3], "diuxX"))
	{
		nb = ft_lstsize(*output);
		if (!nb)
			return ;
		if (!ft_strncmp((*output)->content, "-", 1))
			while (nb++ < tag[2])
				ft_lstadd_front(&(*output)->next, ft_lstnew(ft_strdup("0")));
		else
			while (nb++ < tag[2])
				ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
	}
	else if (is_specifier(tag[3], "s") && is_precision_define && tag[2] == 0)
		ft_lstclear(output, &free);
	else if (is_specifier(tag[3], "s") && is_precision_define && tag[2] > 0)
	{
		while (nb++ < tag[2] - 1 && copy->next)
			copy = copy->next;
		ft_lstclear(&copy->next, &free);
		copy->next = NULL;
	}
	else if (is_specifier(tag[3], "p") && ft_strncmp((*output)->content, "(", 1))
	{
		nb = ft_lstsize(*output) - 2;
		while (nb++ < tag[2])
			ft_lstadd_front(&(*output)->next->next, ft_lstnew(ft_strdup("0")));
	}
}

void	manage_widht(t_list **output, int *tag)
{
	int	nb;

	if (is_specifier(tag[3], "%"))
		return ;
	nb = ft_lstsize(*output);
	if (tag[0] == '-')
	{
		while (nb++ < tag[1])
			ft_lstadd_back(output, ft_lstnew(ft_strdup(" ")));
	}
	else if (tag[0] == '0' && is_specifier(tag[3], "diuxX"))
	{
		if (!ft_strncmp((*output)->content, "-", 1))
			while (nb++ < tag[1])
				ft_lstadd_front(&(*output)->next, ft_lstnew(ft_strdup("0")));
		else
			while (nb++ < tag[1])
				ft_lstadd_front(output, ft_lstnew(ft_strdup("0")));
	}
	else if (tag[0] == '0' && is_specifier(tag[3], "p"))
	{
		if (ft_strncmp((*output)->content, "(", 1))
			while (nb++ < tag[1])
				ft_lstadd_front(&(*output)->next->next, ft_lstnew(ft_strdup("0")));
	}
	else
	{
		while (nb++ < tag[1])
			ft_lstadd_front(output, ft_lstnew(ft_strdup(" ")));
	}
}