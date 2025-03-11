#include "push_swap.h"

void    ft_rev(t_list **list)
{
    t_list *tmp = *list;
    t_list *current;
    int last_value;
    
    if (!tmp || !tmp->next)
        return ;
        
    // Save the last value
    current = tmp;
    while (current->next)
        current = current->next;
    last_value = current->content;
    
    // Start from the end, move each value forward
    while (current != tmp)
    {
        t_list *prev = tmp;
        while (prev->next != current)
            prev = prev->next;
        current->content = prev->content;
        current = prev;
    }
    
    // Put last value at the start
    tmp->content = last_value;
}
void ft_rra(t_list **lst)
{
    ft_rev(lst);
}
void ft_rrb(t_list **lst)
{
    ft_rev(lst);
}
void ft_rrr(t_list **stack_A, t_list **stack_B)
{
    ft_rra(stack_A);
    ft_rrb(stack_B);
}
