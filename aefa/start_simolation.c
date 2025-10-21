/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simolation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:40:09 by sael-kha          #+#    #+#             */
/*   Updated: 2025/06/19 13:26:16 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	precise_sleep(long long ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < ms)
		usleep(100);
}

void	*hayat(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		too_late(philo);
	while (1)
	{
		printf_status(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		printf_status(philo, "has taken a left fork");
		pthread_mutex_lock(philo->right_fork);
		printf_status(philo, "has taken a right fork");
		printf_status(philo, "is eating");
		update_safe(philo);
		precise_sleep(philo->table->time_to_eat);
		printf_status(philo, "is sleeping");
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		check_full(philo);
		precise_sleep(philo->table->time_to_sleep);
		if (check_end(philo))
			return (NULL);
	}
	return (NULL);
}

void	*check_death(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		usleep(500);
		pthread_mutex_lock(&table->protect);
		while (i < table->nbr_of_philo)
		{
			if (table->philo_full == table->nbr_of_philo)
			{
				return (table->end_of_simulation = 1,
					pthread_mutex_unlock(&table->protect), NULL);
			}
			if (table->philos[i].nbr_meals != table->max_meals && 
				(get_time() - table->philos[i].last_time_eat)
				> table->time_to_die)
				return (ft_print_death(table, i), NULL);
			i++;
		}
		pthread_mutex_unlock(&table->protect);
	}
	return (NULL);
}

void	*hayat1(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf_status(philo, "is thinking");
	pthread_mutex_lock(philo->right_fork);
	printf_status(philo, "has taken a right fork");
	precise_sleep(philo->table->time_to_die + 1);
	printf_status(philo, "died");
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int			i;
	pthread_t	checker;

	i = 0;
	table->time_spend = get_time();
	if (table->nbr_of_philo == 1)
	{
		pthread_create(&table->philos[0].thread,
			NULL, hayat1, (void *)&table->philos[0]);
		pthread_join(table->philos[0].thread, NULL);
		return ;
	}
	while (i < table->nbr_of_philo)
	{
		pthread_create(&table->philos[i].thread,
			NULL, hayat, (void *)&table->philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&checker, NULL, check_death, (void *)table);
	while (i < table->nbr_of_philo)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(checker, NULL);
}
