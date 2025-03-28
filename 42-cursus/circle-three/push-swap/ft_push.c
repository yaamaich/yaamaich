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

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!*b)
	{
		*b = first_a;
		(*b)->next = NULL;
	}
	else
	{
		first_a->next = *b;
		(*b)->prev = first_a;
		*b = first_a;
	}
	ft_printf("pb\n");
}
void	ft_pb(t_list **a, t_list **b)
{
	t_list	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (!*b)
	{
		*b = first_a;
		(*b)->next = NULL;
	}
	else
	{
		first_a->next = *b;
		(*b)->prev = first_a;
		*b = first_a;
	}
	ft_printf("pb\n");
}
