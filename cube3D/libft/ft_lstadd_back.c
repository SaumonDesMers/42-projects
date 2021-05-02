#include "libft.h"

void ft_lstadd_back(t_list **start, t_list *new)
{
	t_list *copy_start;

	copy_start = *start;
	if (!*start)
		*start = new;
	else
	{
		while (copy_start->next)
			copy_start = copy_start->next;
		copy_start->next = new;
	}
}