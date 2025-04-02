/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:24:46 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/23 15:12:31 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_operations(t_stack **a, t_stack **b, char *opr)
{
	if ((ft_strncmp(opr, "ra\n", 3)) == 0)
		ra(a, 0);
	else if ((ft_strncmp(opr, "sa\n", 3)) == 0)
		sa(a, 0);
	else if (ft_strncmp(opr, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp(opr, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(opr, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp(opr, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp(opr, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(opr, "pa\n", 3) == 0)
		pa(b, a, 0);
	else if (ft_strncmp(opr, "pb\n", 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(opr, "sb\n", 3) == 0)
		sb(b, 0);
	else if (ft_strncmp(opr, "ss\n", 3) == 0)
		ss(a, b, 0);
	else
		ft_error();
	free(opr);
}

void	read_operations(t_stack **a, t_stack **b)
{
	char	*opr;

	while (1)
	{
		opr = get_next_line(0);
		if (!opr)
			break ;
		check_operations(a, b, opr);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	a = init_stack(ac, av, a);
	if (!a || duplicated(a) == -1)
	{
		free_stack(&a), 
		ft_error();
	}
	read_operations(&a, &b);
	if (!sorted(a) || b)
		write(1, "kO\n", 3);
	else if (sorted(a))
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
}
