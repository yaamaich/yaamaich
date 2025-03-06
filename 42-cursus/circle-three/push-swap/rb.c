#include "push_swap.h"

void	ft_rb(t_list *lst)
{
	t_list *tmp = lst->next;
	int tm;
	while (tmp)
	{
		tm = lst->content;
		lst->content = tmp->content;
		lst = tmp;
		tmp = tmp->next;
	}
}