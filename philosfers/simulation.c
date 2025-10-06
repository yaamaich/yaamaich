/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 05:29:58 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 05:29:58 by yaamaich         ###   ########.fr       */
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

void	*lifes(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	if ((philo->id % 2 ) == 0)
		too_late(philo);
	while (1)
	{	
		print_status(philo, "is thinking");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "his taken right fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "his taken left fork");
		print_status(philo , "is eating");
		philo_safe(philo);
		precise_sleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		check_full(philo);
		precise_sleep(philo->table->time_to_sleep);
		if (check_end(philo))
			return (NULL);
	}
	return (NULL);
}
void	*one_life(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	print_status(philo, "is	thinking");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken right fork");
	precise_sleep(philo->table->time_to_die + 1);
	print_status(philo, "died");
	pthread_mutex_unlock(philo->right_fork);
	
	return (NULL);
}
void *check_death(void *arg)
{
	t_table	*table;
	int i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		usleep(500);
		pthread_mutex_lock(&table->protect);
		while (i < table->nbr_of_philo)
		{
			if (table->philo_full == table->max_meal)
			{
					return (table->end = 1,
						pthread_mutex_unlock(&table->protect), NULL);
			}
			if (table->philos[i].nbr_meals != table->max_meal &&
				(get_time() - table->philos[i].last_time_eat)
				> table->time_to_die)
				return (print_death(i, table), NULL);
			i++;
		}
		pthread_mutex_unlock(&table->protect);
	}
	return (NULL);
}

void	simulation(t_table *table)
{
	int i;
	pthread_t checker;

	i = 0;
	table->time_spend = get_time();
	if (table->nbr_of_philo == 1)
	{
		pthread_create(&table->philos[0].thread, NULL, one_life,
			(void *)&table->philos[0]);
		pthread_join(table->philos[0].thread, NULL);
		return ;
	}
	while (i < table->nbr_of_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, lifes, 
			(void*)&table->philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&checker, NULL, check_death, (void *)table);
	while (i < table->nbr_of_philo)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(checker, NULL);
}
