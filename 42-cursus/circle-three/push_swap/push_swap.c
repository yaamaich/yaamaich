/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:11:25 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/03 23:11:31 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorting(t_swap **llst)
{
	int	size;

	size = ft_lstsize((*llst)->stack_a);
	if (is_sorted((*llst)->stack_a))
	{
		ft_freeswap(*llst);
		exit(0);
	}
	if (size == 2)
		ft_sa(&(*llst)->stack_a);
	else if (size == 3)
		sort_3(&(*llst)->stack_a);
	else if (size <= 5)
		sort_5(&(*llst)->stack_a, &(*llst)->stack_b);
	else
		sort_algo(size, &(*llst)->stack_a, &(*llst)->stack_b);
}

void	ll(void)
{
	system("leaks push_swap");
}

void	initstack(int size, char **str, t_swap *swap)
{
	int	i;

	i = 1;
	while (i < size)
	{
		ft_usesplit(str[i], &swap);
		i++;
	}
	assign_index(&swap->stack_a);
	check_sorting(&swap);
}

int	main(int argc, char **argv)
{
	t_swap	*swap;

	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (0);
	swap->stack_a = NULL;
	swap->stack_b = NULL;
	swap->asize = 0;
	swap->bsize = 0;
	atexit(ll);
	if (argc > 1)
	{
		initstack(argc, argv, swap);
	}
	else
	{
		ft_freeswap(swap);
		ft_exit_error();
	}
	ft_freeswap(swap);
}
