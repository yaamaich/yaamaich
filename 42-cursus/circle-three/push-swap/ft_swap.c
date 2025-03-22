/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:30:10 by yaamaich          #+#    #+#             */
/*   Updated: 2025/03/20 21:45:39 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_list **list)
{
    t_list *head;
    int swap;

    if (!list || !*list || !(*list)->next)
        return;

    head = (*list)->next;
    swap = (*list)->content;
    (*list)->content = head->content;
    head->content = swap;
	ft_printf("sa\n");
}

void ft_sb(t_list **list)
{
    t_list *head;
    int swap;

    if (!list || !*list || !(*list)->next)
        return;

    head = (*list)->next;
    swap = (*list)->content;
    (*list)->content = head->content;
    head->content = swap;
    ft_printf("ba\n");
}

void ft_ss(t_list **stack_A, t_list **stack_B)
{
    ft_sa(stack_A);
    ft_sb(stack_B);
	ft_printf("ss\n");
}