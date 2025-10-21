/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philotools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 05:29:50 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 05:29:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_resources(t_table *table)
{
	int	loop_var;

	loop_var = 0;
	while (loop_var < table->philo_count)
		pthread_mutex_destroy(&table->forks_array[loop_var++]);
	pthread_mutex_destroy(&table->write_lock);
	free(table->forks_array);
	free(table->philosophers);
	free(table);
}

long long	current_time(void)
{
	struct timeval	current_tv;

	gettimeofday(&current_tv, NULL);
	return ((current_tv.tv_sec * 1000) + (current_tv.tv_usec / 1000));
}

void	log_action(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->simulation_stop)
	{
		printf("%lld %d %s\n", current_time() - philo->data->start_time,
			philo->philo_id, status);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	announce_death(int philo_index, t_table *table)
{
	table->simulation_stop = 1;
	printf("%lld %d died\n",
		current_time() - table->start_time, table->philosophers[philo_index].philo_id);
	pthread_mutex_unlock(&table->write_lock);
}

int	is_simulation_over(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->simulation_stop)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	return (0);
}