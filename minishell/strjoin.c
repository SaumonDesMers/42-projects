/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:33:50 by pguignie          #+#    #+#             */
/*   Updated: 2021/09/09 13:54:00 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_malloc(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s2 == NULL)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	if (!s1)
		while (s2[j] == ' ')
			j++;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	free(s1);
	free(s2);
	return (join);
}
