#include "libft.h"

t_list	*ft_lstget_front(t_list **lst)
{
	t_list	*node;

	node = *lst;
	*lst = (*lst)->next;
	node->next = NULL;
	return (node);
}
