/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:10:40 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/23 18:14:48 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	case_diuxX(t_list **output, char specifier, long long value)
{
	if (is_specifier(specifier, "diu"))
	{
		if (specifier == 'u' && value < 0)
		{
			if (!ft_itol(output, value + 4294967296, "0123456789"))
				return (0);
		}
		else
			if (!ft_itol(output, value, "0123456789"))
				return (0);
	}
	else
		if (!case_diuxX_2(output, specifier, value))
			return (0);
	return (1);
}

int	case_diuxX_2(t_list **output, char specifier, long long value)
{
	if (is_specifier(specifier, "x"))
	{
		if (value < 0)
		{
			if (!ft_itol(output, value + 4294967296, "0123456789abcdef"))
				return (0);
		}
		else
			if (!ft_itol(output, value, "0123456789abcdef"))
				return (0);
	}
	else if (specifier == 'X')
	{
		if (value < 0)
		{
			if (!ft_itol(output, value + 4294967296, "0123456789ABCDEF"))
				return (0);
		}
		else
			if (!ft_itol(output, value, "0123456789ABCDEF"))
				return (0);
	}
	return (1);
}

int	manage_precision(t_list **output, int *tag, int is_precision_define)
{
	int	nb;

	nb = 0;
	if (is_specifier(tag[3], "diuxX"))
	{
		nb = ft_lstsize(*output);
		if (!nb)
			return (1);
		if (!ft_strncmp((*output)->content, "-", 1))
		{
			while (nb++ < tag[2] + 1)
				if (!ft_lstadd_front(&(*output)->next,
						ft_lstnew(ft_strdup("0"))))
					return (0);
		}
		else
			while (nb++ < tag[2])
				if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("0"))))
					return (0);
	}
	else
		if (!manage_precision_2(output, tag, is_precision_define))
			return (0);
	return (1);
}

int	manage_precision_2(t_list **output, int *tag, int is_precision_define)
{
	int		nb;
	t_list	*copy;

	nb = 0;
	copy = *output;
	if (is_specifier(tag[3], "s") && is_precision_define && tag[2] == 0)
		ft_lstclear(output, &free);
	else if (
		is_specifier(tag[3], "s")
		&& is_precision_define && tag[2] > 0 && copy)
	{
		while (nb++ < tag[2] - 1 && copy->next)
			copy = copy->next;
		ft_lstclear(&copy->next, &free);
		copy->next = NULL;
	}
	else if (is_specifier(tag[3], "p"))
	{
		nb = ft_lstsize(*output) - 2;
		while (nb++ < tag[2])
			if (!ft_lstadd_front(&(*output)->next->next,
					ft_lstnew(ft_strdup("0"))))
				return (0);
	}
	return (1);
}
