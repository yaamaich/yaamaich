/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:11:25 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/02 22:48:27 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorting(t_swap **llst)
{
	int size = ft_lstsize((*llst)->stack_a);
	if (is_sorted((*llst)->stack_a))
	{
		ft_freeswap(*llst);
		exit(0);
	}
	if ((*llst)->asize == 2)
		ft_sa(&(*llst)->stack_a);
	else if ((*llst)->asize == 3)
		sort_3(&(*llst)->stack_a);
	else if ((*llst)->asize <= 5)
		sort_5(&(*llst)->stack_a, &(*llst)->stack_b);
	else
	    sort_algo(size, &(*llst)->stack_a, &(*llst)->stack_b);
}
void ll(void)
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	atexit(ll);
	if (argc > 1)
	{
		initstack(argc, argv);
	}
	else
		ft_exit_error();
}