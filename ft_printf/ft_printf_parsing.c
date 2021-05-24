/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:15:00 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/23 18:15:02 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	is_specifier(char c, char *specifiers)
{
	int	i;

	i = 0;
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}

char	*take_tags(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	while (!is_specifier(s[i], "cspdiuxX%%"))
		i++;
	dst = malloc(sizeof(char) * (i + 2));
	if (!dst)
		return (0);
	i = 0;
	while (!is_specifier(s[i], "cspdiuxX%%"))
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = s[i];
	dst[++i] = 0;
	return (dst);
}

int	clearlst(t_list **output)
{
	ft_lstclear(output, &free);
	return (-1);
}

int	print_output(t_list *output)
{
	int		nbchar;
	t_list	*copy;

	nbchar = 0;
	copy = output;
	while (copy)
	{
		write(1, (char *)copy->content, 1);
		copy = copy->next;
		nbchar++;
	}
	return (nbchar);
}

int	pars_tags(char *tags, va_list ap)
{
	int		nbchar;
	int		tag[4];
	int		is_precision_define;
	t_list	*output;

	output = NULL;
	is_precision_define = 0;
	tag[3] = ft_specifier(tags);
	tag[1] = ft_widht(tags, ap);
	tag[2] = ft_precision(tags, ap, &is_precision_define);
	tag[0] = ft_flag(tags, tag, is_precision_define);
	if (!manage_specifier(&output, tag, ap))
		return (clearlst(&output));
	if (!manage_precision(&output, tag, is_precision_define))
		return (clearlst(&output));
	if (!manage_widht(&output, tag))
		return (clearlst(&output));
	nbchar = print_output(output);
	ft_lstclear(&output, &free);
	return (nbchar);
}
