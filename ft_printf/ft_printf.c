/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:14:11 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/23 18:14:30 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_printf_2(const char *format, int *i, int *nbchar)
{
	write(1, &format[(*i)++], 1);
	(*nbchar)++;
}

int	ft_printf(const char *format, ...)
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
			tags = take_tags((char *)(format + i + 1));
			nbchar += pars_tags(tags, ap);
			if (nbchar == -1)
				return (-1);
			i += ft_strlen(tags) + 1;
			free(tags);
		}
		else
			ft_printf_2(format, &i, &nbchar);
	}
	va_end(ap);
	return (nbchar);
}
