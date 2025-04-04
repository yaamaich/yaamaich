/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:11:25 by yaamaich          #+#    #+#             */
/*   Updated: 2025/04/04 02:37:42 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ll(void)
{
	system("leaks push_swap");
}
void	initstack(int size, char **str, t_swap *swap)
{
	ft_usesplit(size, str, &swap);
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
	atexit(ll);
	if (argc > 1)
	{
		if (argc == 2 && !argv[1][0])
		{
			ft_freeswap(swap);
			ft_exit_error();
		}
		initstack(argc ,argv, swap);
	}
	else
	{
		ft_freeswap(swap);
		ft_exit_error();
	}
	ft_freeswap(swap);
}
