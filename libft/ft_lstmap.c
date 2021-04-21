#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *newlst;
	t_list *node;

	(void)del;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}