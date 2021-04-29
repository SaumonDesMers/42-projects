typedef struct        s_list
{
    void            *data;
    struct s_list    *next;
}                    t_list;

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(char *, char *))
/*
**    Deux boucles:
**    - la premiere pour decale le debut de la liste, si l'element se situe en debut de liste;
**    - la seconde pour raccorder en milieu de liste.
*/
{
    t_list  *node;
    t_list  *tmp;

    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }
    node = *begin_list;
    while (node && node->next)
    {
        if (cmp(node->next->data, data_ref) == 0)
        {
            tmp = node->next;
            node->next = node->next->next;
            free(tmp);
        }
        node = node->next;
    }
}