/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:15:13 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/23 18:15:16 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_itol(t_list **output, long long n, char *base)
{
	long long	nb;
	char		c[2];

	nb = n;
	c[1] = 0;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("0"))))
			return (0);
	while (nb)
	{
		c[0] = base[nb % ft_strlen(base)];
		if (!ft_lstadd_front(output, ft_lstnew(ft_strdup(c))))
			return (0);
		nb /= ft_strlen(base);
	}
	if (n < 0)
		if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("-"))))
			return (0);
	return (1);
}

int	ft_stol(t_list **output, char *str)
{
	char		c[2];

	c[1] = 0;
	if (!str)
	{
		if (!ft_stol(output, "(null)"))
			return (0);
	}
	else
	{
		while (*str)
		{
			c[0] = *str;
			if (!ft_lstadd_back(output, ft_lstnew(ft_strdup(c))))
				return (0);
			str++;
		}
	}
	return (1);
}

int	ft_ultol(t_list **output, unsigned long n, char *base)
{
	unsigned long	nb;
	char			c[2];

	nb = n;
	c[1] = 0;
	while (nb)
	{
		c[0] = base[nb % ft_strlen(base)];
		if (!ft_lstadd_front(output, ft_lstnew(ft_strdup(c))))
			return (0);
		nb /= ft_strlen(base);
	}
	if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("x"))))
		return (0);
	if (!ft_lstadd_front(output, ft_lstnew(ft_strdup("0"))))
		return (0);
	return (1);
}
