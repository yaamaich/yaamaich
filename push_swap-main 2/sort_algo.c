/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:01:24 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/04/02 17:49:30 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *b, int elements)
{
	int		i;
	int		size;
	t_stack	*tmp;

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

t_stack	*range_algo(int elements, t_stack **a, t_stack **b)
{
	int	min_range;
	int	max_range;

	min_range = 0;
	max_range = elements * 0.048 + 10;
	while (*a)
	{
		if ((*a)->index < min_range)
		{
			pb(a, b);
			min_range++;
			max_range++;
			rb(b, 1);
		}
		else if ((*a)->index >= min_range && (*a)->index <= max_range)
		{
			pb(a, b);
			min_range++;
			max_range++;
		}
		else if ((*a)->index > max_range)
			ra(a, 1);
	}
	return (*b);
}

void	sort_algo(int elements, t_stack **a, t_stack **b)
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
			pa(b, a);
			elements--;
		}
		else if (max_pos < size)
			rb(b, 1);
		else if (max_pos >= size)
			rrb(b, 1);
	}
}

t_stack	*sort_elements(int ac, char **av, t_stack **a, t_stack **b)
{
	int	elements;

	elements = count_nodes(ac, av);
	if (elements == 4 || elements == 5)
		sort_five(ac, av, a, b);
	else if (elements == 3)
		sort_three(a);
	else if (elements == 2)
		sort_two(a);
	else
		sort_algo(elements, a, b);
	return (*a);
}
