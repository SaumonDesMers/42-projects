#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *save;

	while (*lst)
	{
		del((*lst)->content);
		save = *lst;
		*lst = (*lst)->next;
		save->next = NULL;
		free(save);
	}
}