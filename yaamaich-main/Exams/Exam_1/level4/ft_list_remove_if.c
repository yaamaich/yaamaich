#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == '\0' && *begin_list == '\0')
        return ;
    t_list *head = *begin_list;
    if ((*cmp)(head->data , data_ref) == 0)
    {
        *begin_list = head ->next;
        free(head);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    head = *begin_list;
    ft_list_remove_if(&head->next, data_ref, cmp)
}

