#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "libft.h"

void    *addone(void *arg)
{
    void *ret;
    
    ret = malloc(sizeof(int));
    *((int*)ret) = *((int*)arg) + 1;
    return (ret);
}

int     main(void)
{
    t_list *lst1;
    t_list *lst2;
    int val[4] = {0,1,2,3};
    void *(*ft)(void*);

    ft = &addone;
    lst1 = ft_lstnew(&val[0]);
    lst1->next = ft_lstnew(&val[1]);
    lst1->next->next = ft_lstnew(&val[2]);
    lst1->next->next->next = ft_lstnew(&val[3]);

    lst2 = ft_lstmap(lst1, ft, NULL);

    printf("%d %d %d %d\n", *(int*)lst1->content, *(int*)lst1->next->content, *(int*)lst1->next->next->content, *(int*)lst1->next->next->next->content);
    printf("%d %d %d %d\n", *(int*)lst2->content, *(int*)lst2->next->content, *(int*)lst2->next->next->content, *(int*)lst1->next->next->next->content);
    return (0);
}