#include "libft/libft.h"
#include "ft_printf.h"

int	manage_widht(t_list **output, int *tag)
{
	int	nb;

	nb = ft_lstsize(*output);
	if (tag[0] == '0' && is_specifier(tag[3], "diuxX%"))
	{
		if (!ft_strncmp((*output)->content, "-", 1))
		{
			while (nb++ < tag[1])
				if (!ft_lstadd_front(&(*output)->next,
						ft_lstnew(ft_strdup("0"))))
					return (0);
		}
		else
			while (nb++ < tag[1])
				if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("0"))))
					return (0);
	}
	else
		if (!manage_widht_2(output, tag))
			return (0);
	return (1);
}

int	manage_widht_2(t_list **output, int *tag)
{
	int	nb;

	nb = ft_lstsize(*output);
	if (tag[0] == '-')
	{
		while (nb++ < tag[1])
			if (!ft_lstadd_back(output, ft_lstnew(ft_strdup(" "))))
				return (0);
	}
	else if (tag[0] == '0' && is_specifier(tag[3], "p"))
	{
		while (nb++ < tag[1])
			if (!ft_lstadd_front(&(*output)->next->next,
					ft_lstnew(ft_strdup("0"))))
				return (0);
	}
	else
		while (nb++ < tag[1])
			if (!ft_lstadd_front(output, ft_lstnew(ft_strdup(" "))))
				return (0);
	return (1);
}
