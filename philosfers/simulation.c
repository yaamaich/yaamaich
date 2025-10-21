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

void	ft_usleep(long long t)
{
	long long	start;
	long long	diff;

	start = current_time();
	diff = 0;
	while (diff < t)
	{
		usleep(100);
		diff = current_time() - start;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo	*p;
	int		is_even;

	p = (t_philo *)arg;
	is_even = (p->philo_id % 2) == 0;
	if (is_even)
		philo_sleep_routine(p);
	while (1)
	{
		log_action(p, "is thinking");
		pthread_mutex_lock(p->fork_right);
		log_action(p, "has taken a fork");
		pthread_mutex_lock(p->fork_left);
		log_action(p, "has taken a fork");
		log_action(p, "is eating");
		update_meal_status(p);
		ft_usleep(p->data->eating_time);
		pthread_mutex_unlock(p->fork_right);
		pthread_mutex_unlock(p->fork_left);
		check_philo_fullness(p);
		ft_usleep(p->data->sleeping_time);
		if (is_simulation_over(p))
			return (NULL);
	}
	return (NULL);
}
void	*single_philo_routine(void *arg)
{
	t_philo		*p;
	long long	delay;

	p = (t_philo *)arg;
	log_action(p, "is thinking");
	pthread_mutex_lock(p->fork_right);
	log_action(p, "has taken a fork");
	delay = p->data->death_time + 1;
	ft_usleep(delay);
	log_action(p, "died");
	pthread_mutex_unlock(p->fork_right);
	return (NULL);
}
void	*monitor_death(void *arg)
{
	t_table		*t;
	int			i;
	long long	time_diff;
	int			meal_cnt;

	t = (t_table *)arg;
	while (1)
	{
		i = 0;
		usleep(500);
		pthread_mutex_lock(&t->write_lock);
		while (i < t->philo_count)
		{
			if (t->full_philos == t->meals_required)
			{
				t->simulation_stop = 1;
				pthread_mutex_unlock(&t->write_lock);
				return (NULL);
			}
			meal_cnt = t->philosophers[i].meals_count;
			time_diff = current_time() - t->philosophers[i].last_meal_time;
			if (meal_cnt != t->meals_required && time_diff > t->death_time)
				return (announce_death(i, t), NULL);
			i++;
		}
		pthread_mutex_unlock(&t->write_lock);
	}
	return (NULL);
}

void	start_simulation(t_table *t)
{
	int			i;
	pthread_t	monitor;
	int			is_single;

	i = 0;
	t->start_time = current_time();
	is_single = (t->philo_count == 1);
	if (is_single)
	{
		pthread_create(&t->philosophers[0].philo_thread, NULL,
			single_philo_routine, (void *)&t->philosophers[0]);
		pthread_join(t->philosophers[0].philo_thread, NULL);
		return ;
	}
	while (i < t->philo_count)
	{
		pthread_create(&t->philosophers[i].philo_thread, NULL,
			philosopher_routine, (void *)&t->philosophers[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitor, NULL, monitor_death, (void *)t);
	while (i < t->philo_count)
	{
		pthread_join(t->philosophers[i].philo_thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}
