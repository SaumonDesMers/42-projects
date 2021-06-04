/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_tags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:13:53 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/23 18:14:38 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	ft_specifier(char *tags)
{
	while (*(tags + 1))
		tags++;
	return (*tags);
}

int	ft_widht(char *tags, va_list ap)
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
		return (widht);
	}
	while (tags[i] != '.' && !is_specifier(tags[i], "cspdiuxX%%"))
		widht = widht * 10 + tags[i++] - 48;
	return (widht);
}

int	ft_precision(char *tags, va_list ap, int *is_precision_define)
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

char	ft_flag(char *tags, int *int_tag, int is_precision_define)
{
	if (int_tag[1] < 0)
	{
		int_tag[1] = -int_tag[1];
		return ('-');
	}
	if (tags[0] == '-' || tags[1] == '-')
		return ('-');
	if (is_specifier(int_tag[3], "cs"))
		return (0);
	if (
		tags[0] == '0'
		&& (!is_precision_define || (is_precision_define && int_tag[2] < 0)))
		return ('0');
	return (0);
}
