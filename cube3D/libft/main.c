#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "libft.h"

int        main(void)
{
    t_list **start;
    t_list *node;

    *start = NULL;
    node = ft_lstnew("b");

    ft_lstadd_back(start, node);

    while (*start)
    {
        printf("%s\n", (char*)(*start)->content);
        *start = (*start)->next;
    }
    return (0);
}