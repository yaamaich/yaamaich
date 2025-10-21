/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 05:29:50 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 05:29:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	is_simulation_over(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->simulation_end)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	return (0);
}

void	display_status(t_philosopher *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->simulation_end)
	{
		printf("%lld, %d, %s\n", get_current_time() - philo->data->start_time,
			philo->philosopher_id, msg);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	display_death(int index, t_data *data)
{
	data->simulation_end = 1;
	printf("%lld, %d, died\n",
		get_current_time() - data->start_time, data->philosophers[index].philosopher_id);
	pthread_mutex_unlock(&data->write_lock);
}

void	cleanup_resources(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_philosophers)
	{
		pthread_mutex_destroy(&data->forks[idx]);
		idx++;
	}
	pthread_mutex_destroy(&data->write_lock);
	free(data->forks);
	free(data->philosophers);
	free(data);
}