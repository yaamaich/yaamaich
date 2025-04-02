#include "push_swap.h"

int	find_min(t_list *stack)
{
	t_list	*temp;
	t_list	*min;

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

int	findmax(t_list *stack)
{
	t_list	*temp;
	t_list	*max;

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

void	sort_3(t_list **stack_a)
{
	int	max;

	max = findmax(*stack_a);
	if ((*stack_a)->content == max)
		ft_ra(stack_a);
	else if ((*stack_a)->next->content == max)
		ft_rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}
void	sort_5(t_list **a, t_list **b)
{
	int	count;
	int	size;

	count = 0;
	size = ft_lstsize(*a);
	while (count < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			ft_pb(b, a);
			count++;
		}
		else
			ft_ra(a);
	}
	if (size == 5)
		sort_3(a);
	if ((*b)->content < (*b)->next->content)
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
}
