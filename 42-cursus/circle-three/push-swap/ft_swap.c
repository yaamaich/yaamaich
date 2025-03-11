#include "push_swap.h" // Include the header file where t_list is defined

void ft_sa(t_list **list)
{
    t_list *head;
    int swap;

    if (!list || !*list || !(*list)->next)
        return;

    head = (*list)->next;
    swap = (*list)->content;
    (*list)->content = head->content;
    head->content = swap;
}

void ft_sb(t_list **list)
{
    t_list *head;
    int swap;

    if (!list || !*list || !(*list)->next)
        return;

    head = (*list)->next;
    swap = (*list)->content;
    (*list)->content = head->content;
    head->content = swap;
}

void ft_ss(t_list **stack_A, t_list **stack_B)
{
    ft_sa(stack_A);
    ft_sb(stack_B);
}