/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:10 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/03 22:55:32 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!(*a) || !(*a)->next)
		return ;
	second = (*a)->next;
	first = *a;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	ft_sa(t_list **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_list **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_list **stack_A, t_list **stack_B)
{
	ft_swap(stack_A);
	ft_swap(stack_B);
	ft_printf("ss\n");
}
