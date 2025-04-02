/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:49:19 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 17:56:40 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*prev;
	t_stack	*tmp;

	tmp = *head;
	prev = NULL;
	if (!*head || !head || (*head)->next == NULL)
		return ;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	tmp->next = *head;
	*head = tmp;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
}
