/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:10:16 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/04/02 17:48:31 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		count;

	current = *a;
	while (current)
	{
		count = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->data < current->data)
				count++;
			tmp = tmp->next;
		}
		current->index = count;
		current = current->next;
	}
}
