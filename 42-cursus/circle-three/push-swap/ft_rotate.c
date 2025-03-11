#include "push_swap.h"

void	ft_ra(t_list **lst)
{
    t_list *tmp = (*lst)->next;
	int tm;
    tm = (*lst)->content;
	while (tmp)
	{
		(*lst)->content = tmp->content;
        tmp->content = tm;
		*lst = tmp;
		tmp = tmp->next;
	}
}
void	ft_rb(t_list **lst)
{
	t_list *tmp = (*lst)->next;
	int tm;
    tm = (*lst)->content;
	while (tmp)
	{
		(*lst)->content = tmp->content;
        tmp->content = tm;
		*lst = tmp;
		tmp = tmp->next;
	}
}
void    ft_rr(t_list **stack_A, t_list **stack_B)
{
    ft_ra(stack_A);
    ft_rb(stack_B);
}
