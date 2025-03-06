#include "push_swap.h"

void ft_sb(t_list *list)
{
	t_list *head = list->next;
	int swap;
	int i = 1;
	while (i > 0)
	{
		swap = list->content;
		list->content = head->content;
		head->content = swap;
		i--;
	}
}