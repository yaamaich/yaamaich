/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:59:04 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/02 20:59:04 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ft_ra(t_list **lst)
{
	ft_r(lst);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **lst)
{
	ft_r(lst);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **stack_A, t_list **stack_B)
{
	if (!stack_A || !stack_B)
		return ;
	if (!*stack_A || !*stack_B)
		return ;
	ft_r(stack_A);
	ft_r(stack_B);
	ft_putstr_fd("rr\n", 1);
}
