#include "push_swap.h"

int main(int argc , char **argv)
{
	if (argc >= 2)
	{
		t_list *head = ft_lstnew(ft_atoi(argv[1]));
    	if (!head)
    	{
        	printf("No valid numbers provided.\n");
        	return (1);
    	}
    	t_list *current = head;
		int i = 2;
		while (i < argc)
		{
        	current->next = ft_lstnew(ft_atoi(argv[i]));
        	current = current->next;
			i++;
		}
		ft_sa(head);
		ft_pa(&head, 90);
		ft_ra(head);
		while (head)
		{
			printf("%d\n", head->content);
			head = head->next;
		}
		ft_freelst(head);
	}
	return (0);
}