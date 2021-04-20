#include "libft.h"

void ft_lstadd_front(t_list **start, t_list *new)
{
	new->next = *start;
	*start = new;
}