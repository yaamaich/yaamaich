/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:10 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/28 07:25:52 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_s(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	first = *lst;
	second = (*lst)->next;
	if (second->next)
	{
		first->next = second->next;
		second->next->prev = first;
	}
	else
		first->next = NULL;
	second->next = first;
	second->prev = NULL;
	*lst = second;
}
void    ft_sa(t_list **list)
{
    ft_s(list);
	ft_printf("sa\n");
}
void ft_sb(t_list **list)
{
    ft_s(list);
    ft_printf("ba\n");
}

void ft_ss(t_list **stack_A, t_list **stack_B)
{
    ft_s(stack_A);
    ft_s(stack_B);
	ft_printf("ss\n");
}