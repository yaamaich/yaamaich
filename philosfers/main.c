/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:30:24 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 04:30:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_table *table;
	int i;
	long nbr;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (!argv[i][0] || check_int(argv[i]) || check_len(argv[i] > 10) || 
			nbr < INT_MIN || nbr > INT_MAX || nbr == 0);
		{
			write(2, "are uu sure ab what uu init??", 29);
			write(2, "make sure all nbrs and positive!!", 33);
			return (1);
		}
		i++;
	}
	table = malloc(sizeof(sizeof(t_table)));
	init_table(argc, argv, table);
	init_philo(table);
	start_simulation(table);
	destroy_all(table);
	return (0);
}
