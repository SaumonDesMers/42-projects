#include "libft.h"
#include <stdio.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *newlst;

	(void)del;
	newlst = NULL;
	while (lst)
	{
		ft_lstadd_back(&newlst, ft_lstnew(f(lst->content)));
		printf("%d\n", *(int*)newlst->content);
		lst = lst->next;
	}
	return (newlst);
}