/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:58:13 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/02 22:02:54 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	find_max(t_list *b, int elements)
{
	int		i;
	int		size;
	t_list	*tmp;

	size = elements - 1;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index == size)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*range_algo(int elements, t_list **a, t_list **b)
{
	int	min_range;
	int	max_range;

	min_range = 0;
	max_range = elements * 0.05 + 10;
	while (*a)
	{
		if ((*a)->index < min_range)
		{
			ft_pb(b, a);
			min_range++;
			max_range++;
			ft_rb(b);
		}
		else if ((*a)->index >= min_range && (*a)->index <= max_range)
		{
			ft_pb(b, a);
			min_range++;
			max_range++;
		}
		else if ((*a)->index > max_range)
			ft_ra(a);
	}
	return (*b);
}

void	sort_algo(int elements, t_list **a, t_list **b)
{
	int	size;
	int	max_pos;

	*b = range_algo(elements, a, b);
	while ((*b))
	{
		max_pos = find_max(*b, elements);
		size = elements / 2;
		if ((*b)->index == elements - 1)
		{
			ft_pa(a, b);
			elements--;
		}
		else if (max_pos < size)
			ft_rb(b);
		else if (max_pos >= size)
			ft_rrb(b);
	}
}

