/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:19:46 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 12:19:46 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_resources(t_table *t)
{
	int	i;

	i = 0;
	while (i < t->philo_count)
	{
		pthread_mutex_destroy(&t->forks_array[i]);
		i++;
	}
	pthread_mutex_destroy(&t->write_lock);
	free(t->forks_array);
	free(t->philosophers);
	free(t);
}

long long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	log_action(t_philo *p, char *msg)
{
	long long	timestamp;
	int			id;

	pthread_mutex_lock(&p->data->write_lock);
	if (!p->data->simulation_stop)
	{
		timestamp = current_time() - p->data->start_time;
		id = p->philo_id;
		printf("%lld %d %s\n", timestamp, id, msg);
	}
	pthread_mutex_unlock(&p->data->write_lock);
}

void	announce_death(int i, t_table *t)
{
	long long	timestamp;
	int			id;

	t->simulation_stop = 1;
	timestamp = current_time() - t->start_time;
	id = t->philosophers[i].philo_id;
	printf("%lld %d died\n", timestamp, id);
	pthread_mutex_unlock(&t->write_lock);
}

int	is_simulation_over(t_philo *p)
{
	int	stop;

	pthread_mutex_lock(&p->data->write_lock);
	stop = p->data->simulation_stop;
	pthread_mutex_unlock(&p->data->write_lock);
	if (stop)
		return (1);
	return (0);
}
