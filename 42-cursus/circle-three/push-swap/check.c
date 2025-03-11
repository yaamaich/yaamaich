#include "push_swap.h"

void sort_3(t_list **stack_a)
{
    int a;
    int b;
    int c;

    a = (*stack_a)->content;
    b = (*stack_a)->next->content;
    c = (*stack_a)->next->next->content;
    if (a > b && b < c && a < c)
        ft_sa(stack_a);
    else if (a > b && b > c && a > c)
    {
        ft_sa(stack_a);
        ft_rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ft_ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        ft_sa(stack_a);
        ft_ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        ft_rra(stack_a);
}
int find_min (t_list *stack)
{
    t_list *temp;
    t_list *min;

    temp = stack;
    min = temp;
    while (temp)
    {
        if (temp->content < min->content)
            min = temp;
        temp = temp->next;
    }
    return (min->content);
}
int find_max (t_list *stack)
{
    t_list *temp;
    t_list *max;

    temp = stack;
    max = temp;
    while (temp)
    {
        if (temp->content > max->content)
            max = temp;
        temp = temp->next;
    }
    return (max->content);
}

void    sort_5(t_list **stack_a, t_list **stack_b)
{
    int     i;
    int     min;
    int     max;
    int     size;
    t_list  *temp;

    size = ft_lstsize(*stack_a);
    while (size > 3)
    {
        min = find_min(*stack_a);
        max = find_max(*stack_a);
        i = 0;
        while (i < size)
        {
            temp = *stack_a;
            if (temp->content == min || temp->content == max)
            {
                ft_pb(stack_b, stack_a);
                if ((*stack_b)->content == max)
                    ft_rb(stack_b);
                break ;
            }
            ft_ra(stack_a);
            i++;
        }
        size--;
    }
    sort_3(stack_a);
    while (*stack_b)
        ft_pa(stack_a, stack_b);
}