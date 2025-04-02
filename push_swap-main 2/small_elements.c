/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:55:15 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/09 20:55:38 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void	sort_five(int ac, char **av, t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a, 1);
	}
	if (count_nodes(ac, av) == 4)
		sort_two(a);
	if (count_nodes(ac, av) == 5)
		sort_three(a);
	if ((*b)->data < (*b)->next->data)
		sb(b, 1);
	pa(b, a);
	pa(b, a);
}
