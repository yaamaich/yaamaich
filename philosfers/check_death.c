/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:12:35 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 16:11:18 by yaamaich         ###   ########.fr       */
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

void	*monitor_death(void *arg)
{
	t_table		*t;
	int			i;

	t = (t_table *)arg;
	while (1)
	{
		i = 0;
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
