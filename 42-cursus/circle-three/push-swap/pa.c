#include "push_swap.h"

void ft_pa(t_list **pa, int put)
{
	t_list *new = ft_lstnew(put);
	if (!pa || !new)
		return ;
	if (pa && new)
	{
		new->next = *pa;
		*pa = new;
	}
}