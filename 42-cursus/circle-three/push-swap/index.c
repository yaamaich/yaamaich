/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:10:16 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/04/02 20:08:12 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_list **a)
{
	t_list	*current;
	t_list	*tmp;
	int		count;

	current = *a;
	while (current)
	{
		count = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->content < current->content)
				count++;
			tmp = tmp->next;
		}
		current->index = count;
		current = current->next;
	}
}
