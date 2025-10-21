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

void	precise_sleep(long long milliseconds)
{
	long long	begin;

	begin = get_current_time();
	while (get_current_time() - begin < milliseconds)
		usleep(100);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if ((philo->philosopher_id % 2) == 0)
		perform_sleep(philo);
	while (1)
	{
		display_status(philo, "is thinking");
		pthread_mutex_lock(philo->fork_right);
		display_status(philo, "his taken right fork");
		pthread_mutex_lock(philo->fork_left);
		display_status(philo, "his taken left fork");
		display_status(philo, "is eating");
		update_meal_status(philo);
		precise_sleep(philo->data->eat_time);
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		verify_completion(philo);
		precise_sleep(philo->data->sleep_time);
		if (is_simulation_over(philo))
			return (NULL);
	}
	return (NULL);
}
void	*single_philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	display_status(philo, "is	thinking");
	pthread_mutex_lock(philo->fork_right);
	display_status(philo, "has taken right fork");
	precise_sleep(philo->data->death_time + 1);
	display_status(philo, "died");
	pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}
void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		idx;

	data = (t_data *)arg;
	while (1)
	{
		idx = 0;
		usleep(500);
		pthread_mutex_lock(&data->write_lock);
		while (idx < data->num_philosophers)
		{
			if (data->full_philosophers == data->required_meals)
			{
				data->simulation_end = 1;
				pthread_mutex_unlock(&data->write_lock);
				return (NULL);
			}
			if (data->philosophers[idx].meals_eaten != data->required_meals
				&& (get_current_time()
					- data->philosophers[idx].last_meal_time)
				> data->death_time)
				return (display_death(idx, data), NULL);
			idx++;
		}
		pthread_mutex_unlock(&data->write_lock);
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	int			idx;
	pthread_t	monitor;

	idx = 0;
	data->start_time = get_current_time();
	if (data->num_philosophers == 1)
	{
		pthread_create(&data->philosophers[0].life_thread, NULL,
			single_philo_routine, (void *)&data->philosophers[0]);
		pthread_join(data->philosophers[0].life_thread, NULL);
		return ;
	}
	while (idx < data->num_philosophers)
	{
		pthread_create(&data->philosophers[idx].life_thread, NULL,
			philosopher_routine, (void *)&data->philosophers[idx]);
		idx++;
	}
	idx = 0;
	pthread_create(&monitor, NULL, monitor_routine, (void *)data);
	while (idx < data->num_philosophers)
	{
		pthread_join(data->philosophers[idx].life_thread, NULL);
		idx++;
	}
	pthread_join(monitor, NULL);
}
