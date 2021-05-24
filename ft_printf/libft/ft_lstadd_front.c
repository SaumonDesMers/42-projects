/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:43:31 by sgaubert          #+#    #+#             */
/*   Updated: 2021/05/21 14:43:34 by sgaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **start, t_list *new)
{
	if (!new)
		return (0);
	new->next = *start;
	*start = new;
	return (1);
}
