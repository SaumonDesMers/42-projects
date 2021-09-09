/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:15:34 by pguignie          #+#    #+#             */
/*   Updated: 2021/09/08 14:15:59 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_quote(char c, int *quote)
{
	if (c == '\'' && !(*quote))
		*quote = 1;
	else if (c == '\"' && !(*quote))
		*quote = 2;
	else if ((c == '\'' && *quote == 1) || (c == '\"' && *quote == 2))
		*quote = 0;
}

int	ft_check_str(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		ft_check_quote(str[i], &quote);
		i++;
	}
	if (quote)
		return (0);
	return (1);
}
