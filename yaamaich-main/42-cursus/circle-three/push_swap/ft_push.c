/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:23 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/20 19:30:23 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack1, t_list **stack2)
{
	t_list	*head_b;

	if (!*stack2)
		return ;
	head_b = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = head_b;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_list **stack_b, t_list **satck_a)
{
	t_list	*head_a;

	if (!*satck_a)
		return ;
	head_a = (*satck_a)->next;
	(*satck_a)->next = *stack_b;
	*stack_b = *satck_a;
	*satck_a = head_a;
	ft_putstr_fd("pb\n", 1);
}
