/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:12:36 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 17:54:59 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*new_head;

	if (!*head || !head || (*head)->next == NULL)
		return ;
	tmp = *head;
	new_head = tmp->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	*head = new_head;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print == 1)
		write(1, "rb\n", 3);
}
