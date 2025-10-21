/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:49:37 by sael-kha          #+#    #+#             */
/*   Updated: 2025/06/19 13:27:02 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_safe(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	philo->last_time_eat = get_time();
	philo->nbr_meals++;
	pthread_mutex_unlock(&philo->table->protect);
}

void	too_late(t_philo *philo)
{
	printf_status(philo, "is sleeping");
	precise_sleep(philo->table->time_to_sleep);
}

void	ft_print_death(t_table *table, int i)
{
	table->end_of_simulation = 1;
	printf("%lld %d died\n",
		get_time() - table->time_spend, table->philos[i].id);
	pthread_mutex_unlock(&table->protect);
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		i;
	long	nbr;

	i = 1;
	if (ac < 5 || ac > 6)
		return (1);
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (!av[i][0] || check_int(av[i]) || check_len(av[i]) > 10 || 
			(nbr < INT_MIN && nbr > INT_MAX) || nbr == 0)
		{
			write(2, "give me only nbrs lady ", 23);
			write(2, "and make them positive\n", 23);
			return (1);
		}
		i++;
	}
	table = malloc(sizeof(t_table));
	init_table(table, ac, av);
	init_philo(table);
	start_simulation(table);
	destroy_all(table);
	return (0);
}
