#include "libft.h"

void ft_lstadd_back(t_list **start, t_list *new)
{
	if (!*start)
		return ;
	while ((*start)->next)
		*start = (*start)->next;
	(*start)->next = new;
}