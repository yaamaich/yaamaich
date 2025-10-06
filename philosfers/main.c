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
void philo_safe(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	philo->last_time_eat = get_time();
	philo->nbr_meals++;
	pthread_mutex_unlock(&philo->table->protect);
}
void	too_late(t_philo *philo)
{
	print_status(philo, "is sleeping");
	precise_sleep(philo->table->time_to_sleep);
}
void	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (philo->nbr_meals != -1 && 
		philo->nbr_meals == philo->table->max_meal)
		philo->table->philo_full++;
	pthread_mutex_unlock(&philo->table->protect);
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
			nbr < INT_MIN || nbr > INT_MAX || nbr == 0)
		{
			write(2, "are uu sure ab what uu inter lady??", 29);
			write(2, "make sure all nbrs and positive!!\n", 33);
			return (1);
		}
		i++;
	}
	table = malloc(sizeof(t_table));
	init_table(ac, av, table);
	init_philo(table);
	simulation(table);
	destroy_all(table);
	return (0);
}
