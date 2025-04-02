/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:40:58 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 17:56:00 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	second = (*a)->next;
	first = *a;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sa(t_stack **a, int print)
{
	ft_swap(a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	ft_swap(b);
	if (print == 1)
		write(1, "sb\n", 3);
}
