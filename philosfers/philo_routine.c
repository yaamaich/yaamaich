/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:29:58 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 12:29:58 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long t, t_philo *p)
{
	long long	start;
	long long	elapsed;

	start = current_time();
	elapsed = 0;
	while (elapsed < t)
	{
		if (is_simulation_over(p))
			return ;
		usleep(100);
		elapsed = current_time() - start;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->philo_id % 2 == 0)
		philo_sleep_routine(p);
	while (!is_simulation_over(p))
	{
		log_action(p, "is thinking");
		if (is_simulation_over(p))
			return (NULL);
		pthread_mutex_lock(p->fork_right);
		log_action(p, "has taken a fork");
		pthread_mutex_lock(p->fork_left);
		log_action(p, "has taken a fork");
		log_action(p, "is eating");
		update_meal_status(p);
		ft_usleep(p->data->eating_time, p);
		pthread_mutex_unlock(p->fork_right);
		pthread_mutex_unlock(p->fork_left);
		check_philo_fullness(p);
		if (is_simulation_over(p))
			return (NULL);
		ft_usleep(p->data->sleeping_time, p);
	}
	return (NULL);
}

void	*single_philo_routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	log_action(p, "is thinking");
	pthread_mutex_lock(p->fork_right);
	log_action(p, "has taken a fork");
	ft_usleep(p->data->death_time + 1, p);
	log_action(p, "died");
	pthread_mutex_unlock(p->fork_right);
	return (NULL);
}

static int	check_death_condition(t_table *t, int i)
{
	long long	time_diff;
	int			meal_cnt;

	meal_cnt = t->philosophers[i].meals_count;
	time_diff = current_time() - t->philosophers[i].last_meal_time;
	if (meal_cnt != t->meals_required && time_diff > t->death_time)
		return (1);
	return (0);
}

void	*monitor_death(void *arg)
{
	t_table		*t;
	int			i;

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
			if (check_death_condition(t, i))
				return (announce_death(i, t), NULL);
			i++;
		}
		pthread_mutex_unlock(&t->write_lock);
	}
	return (NULL);
}

static void	create_threads(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->philo_count)
	{
		pthread_create(&t->philosophers[i].philo_thread, NULL,
			philosopher_routine, (void *)&t->philosophers[i]);
		i++;
	}
}

static void	join_threads(t_table *t, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < t->philo_count)
	{
		pthread_join(t->philosophers[i].philo_thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

void	start_simulation(t_table *t)
{
	pthread_t	monitor;
	int			is_single;

	t->start_time = current_time();
	is_single = (t->philo_count == 1);
	if (is_single)
	{
		pthread_create(&t->philosophers[0].philo_thread, NULL,
			single_philo_routine, (void *)&t->philosophers[0]);
		pthread_join(t->philosophers[0].philo_thread, NULL);
		return ;
	}
	create_threads(t);
	pthread_create(&monitor, NULL, monitor_death, (void *)t);
	join_threads(t, monitor);
}
