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

int	find_max(t_list *stack)
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

	max = find_max(*stack_a);
	if ((*stack_a)->content == max)
		ft_ra(stack_a);
	else if ((*stack_a)->next->content == max)
		ft_rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	check_push(int size, int min, t_list **stack_a,
		t_list **stack_b)
{
	int		i;
	t_list	*temp;

	while (size > 3)
	{
		i = 0;
		while (i < size)
		{
			temp = *stack_a;
			if (temp->content == min)
			{
				ft_pb(stack_b, stack_a);
				if ((*stack_b)->content == min)
					ft_rb(stack_b);
				break ;
			}
			ft_ra(stack_a);
			i++;
		}
		size--;
	}
}
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	max;
	int	size;

	min = find_min(*stack_a);
	max = find_max(*stack_a);
	size = ft_lstsize(*stack_a);
	check_push(size, min, stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
	if ((*stack_a)->content == max)
		ft_ra(stack_a);
}
// void	ft_push_max(t_list **stack_b, t_list **stack_a, int max)
// {
// 	t_list	*temp;
// 	int		pos;
// 	int		size;

// 	temp = *stack_b;
// 	pos = 0;
// 	size = ft_lstsize(*stack_b);
// 	// البحث عن موقع أكبر رقم
// 	while (temp)
// 	{
// 		if (temp->content == max)
// 			break ;
// 		temp = temp->next;
// 		pos++;
// 	}
// 	// تحريك `stack_b` بحيث يصبح أكبر رقم في القمة
// 	if (pos <= size / 2)
// 	{
// 		while ((*stack_b)->content != max)
// 			ft_rb(stack_b); // تدوير `stack_b` للأعلى
// 	}
// 	else
// 	{
// 		while ((*stack_b)->content != max)
// 			ft_rrb(stack_b); // تدوير `stack_b` للأسفل
// 	}
// 	// نقل (`push`) أكبر رقم إلى `stack_a`
// 	ft_pa(stack_a, stack_b);
// }

// int	ft_check_max(t_list *stack)
// {
// 	int	max;

// 	if (!stack)
// 		return (0); // إذا كانت القائمة فارغة، نعيد 0 أو قيمة مناسبة
// 	max = stack->content;
// 	while (stack)
// 	{
// 		if (stack->content > max)
// 			max = stack->content;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

// void	sort_algo(t_swap **swap)
// {
// 	ft_stack_sort(&(*swap)->stack_a, &(*swap)->stack_b);
// }