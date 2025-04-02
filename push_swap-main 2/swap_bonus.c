/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:55:29 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 17:55:54 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}
