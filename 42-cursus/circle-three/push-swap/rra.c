#include "push_swap.h"

t_list *ft_rr(t_list *lst)
{
    t_list *current;
    int last_value;
    
    if (!lst || !lst->next)
        return NULL;
        
    // Save the last value
    current = lst;
    while (current->next)
        current = current->next;
    last_value = current->content;
    
    // Start from the end, move each value forward
    while (current != lst)
    {
        t_list *prev = lst;
        while (prev->next != current)
            prev = prev->next;
        current->content = prev->content;
        current = prev;
    }
    
    // Put last value at the start
    lst->content = last_value;
	return lst;
}