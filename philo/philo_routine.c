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

void	*philosopher_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->philo_id % 2 == 0)
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

int	check_death_condition(t_table *t, int i)
{
	long long	time_diff;
	int			meal_cnt;

	meal_cnt = t->philosophers[i].meals_count;
	time_diff = current_time() - t->philosophers[i].last_meal_time;
	if (meal_cnt != t->meals_required && time_diff > t->death_time)
		return (1);
	return (0);
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
