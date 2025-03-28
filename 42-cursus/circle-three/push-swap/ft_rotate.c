/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:17 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/20 19:30:17 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}
void	ft_ra(t_list **lst)
{
	ft_r(lst);
	ft_printf("ra\n");
}
void	ft_rb(t_list **lst)
{
	ft_r(lst);
	ft_printf("rb\n");
}
void    ft_rr(t_list **stack_A, t_list **stack_B)
{
	if (!stack_A || !stack_B)
		return ;
	if (!*stack_A || !*stack_B)
		return ;
    ft_r(stack_A);
    ft_r(stack_B);
	ft_printf("rr\n");
}
