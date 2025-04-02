/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-afi <ouel-afi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:07:11 by ouel-afi          #+#    #+#             */
/*   Updated: 2025/02/14 16:15:04 by ouel-afi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fun_free(char **split, t_stack *a)
{
	free_work_split(split);
	free_stack(&a);
	ft_error();
}

t_stack	*init_stack(int ac, char **av, t_stack *a)
{
	int		i;
	int		j;
	char	**split;
	t_stack	*new_node;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			ft_error();
		j = 0;
		while (split[j])
		{
			if (valid_int(split[j]) == -1)
				fun_free(split, a);
			new_node = ft_lstnew(ft_atoi(split[j]));
			if (!new_node)
				fun_free(split, a);
			(ft_lstadd_back(&a, new_node), j++);
		}
		free_work_split(split);
		i++;
	}
	return (a);
}
