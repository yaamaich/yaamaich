/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:25:02 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/04/02 17:42:23 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!av[i][0])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (check_args(ac, av) == 0)
		ft_error();
	a = init_stack(ac, av, a);
	if (!a || duplicated(a) == -1)
	{
		free_stack(&a), 
		ft_error();
	}
	if (sorted(a))
		return (free_stack(&a), 0);
	assign_index(&a);
	sort_elements(ac, av, &a, &b);
	free_stack(&a);
	free_stack(&b);
}
