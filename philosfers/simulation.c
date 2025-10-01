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

void	lifes(void *args)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	print_status(philo, "is thinking");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "his taken right fork");
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "his taken left fork");
	print_status(philo)
}
void	one_life(void *arg)
{
	t_philo *philo;
	philo = (t_philo *)arg;
	print_status(philo, "is	thinking");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken right fork");
	precise_sleep(philo->table->time_to_die, + 1);
	print_status(philo, "died");
	pthread_mutex_unlock(philo->right_fork);
	
	return (NULL);
}
void	simolation(t_table *table)
{
	int i;
	pthread_t checker;

	i = 0;
	table->time_spend = get_time();
	if (table->nbr_of_philo == 1)
	{
		pthread_creat(&table->philos[0].thread, NULL, life1,
			 NULL, (void *)&table->philos[0]);
		pthread_join(table->philos[0].thread, NULL);
		return ;
	}
	while (i < table->nbr_of_philo)
	{
		pthread_creat(&table->philos[i].thread, NULL, lifes, 
			NULL, (void*)&table->philos[i].thread)
		i++;
	}
	i = 0;
	pthread_creat(&checker, NULL, check_die, NULL, (void *)table);
	while (i < table->nbr_of_philo)
		pthread_join(table->philos[i++].thread, NULL);
	pthread_join(checker, NULL);
}