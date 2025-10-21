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

void	ft_usleep(long long ms)
{
	long long	begin_time;

	begin_time = current_time();
	while (current_time() - begin_time < ms)
		usleep(100);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	if ((philosopher->philo_id % 2) == 0)
		philo_sleep_routine(philosopher);
	while (1)
	{
		log_action(philosopher, "is thinking");
		pthread_mutex_lock(philosopher->fork_right);
		log_action(philosopher, "has taken a fork");
		pthread_mutex_lock(philosopher->fork_left);
		log_action(philosopher, "has taken a fork");
		log_action(philosopher, "is eating");
		update_meal_status(philosopher);
		ft_usleep(philosopher->data->eating_time);
		pthread_mutex_unlock(philosopher->fork_right);
		pthread_mutex_unlock(philosopher->fork_left);
		check_philo_fullness(philosopher);
		ft_usleep(philosopher->data->sleeping_time);
		if (is_simulation_over(philosopher))
			return (NULL);
	}
	return (NULL);
}
void	*single_philo_routine(void *arg)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)arg;
	log_action(philosopher, "is thinking");
	pthread_mutex_lock(philosopher->fork_right);
	log_action(philosopher, "has taken a fork");
	ft_usleep(philosopher->data->death_time + 1);
	log_action(philosopher, "died");
	pthread_mutex_unlock(philosopher->fork_right);
	return (NULL);
}
void	*monitor_death(void *arg)
{
	t_table	*table;
	int		checker;

	table = (t_table *)arg;
	while (1)
	{
		checker = 0;
		usleep(500);
		pthread_mutex_lock(&table->write_lock);
		while (checker < table->philo_count)
		{
			if (table->full_philos == table->meals_required)
			{
				table->simulation_stop = 1;
				pthread_mutex_unlock(&table->write_lock);
				return (NULL);
			}
			if (table->philosophers[checker].meals_count != table->meals_required
				&& (current_time() - table->philosophers[checker].last_meal_time)
				> table->death_time)
				return (announce_death(checker, table), NULL);
			checker++;
		}
		pthread_mutex_unlock(&table->write_lock);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int			philo_iter;
	pthread_t	death_monitor;

	philo_iter = 0;
	table->start_time = current_time();
	if (table->philo_count == 1)
	{
		pthread_create(&table->philosophers[0].philo_thread, NULL,
			single_philo_routine, (void *)&table->philosophers[0]);
		pthread_join(table->philosophers[0].philo_thread, NULL);
		return ;
	}
	while (philo_iter < table->philo_count)
	{
		pthread_create(&table->philosophers[philo_iter].philo_thread, NULL,
			philosopher_routine, (void *)&table->philosophers[philo_iter]);
		philo_iter++;
	}
	philo_iter = 0;
	pthread_create(&death_monitor, NULL, monitor_death, (void *)table);
	while (philo_iter < table->philo_count)
		pthread_join(table->philosophers[philo_iter++].philo_thread, NULL);
	pthread_join(death_monitor, NULL);
}
