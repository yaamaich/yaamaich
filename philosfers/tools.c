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

void	destroy_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->protect);
	free(table->forks);
	free(table->philos);
	free(table);
}

long long	get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->protect);
	if (!philo->table->end)
	{
		printf("%lld, %d, %s\n", get_time() - philo->table->time_spend, 
			philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->protect);
}

void	print_death(int i, t_table *table)
{
	table->end = 1;
	printf("%lld, %d, died\n",
		get_time() - table->time_spend, table->philos[i].id);
	pthread_mutex_unlock(&table->protect);
}

int	check_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (philo->table->end)
	{
		pthread_mutex_unlock(&philo->table->protect);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->protect);
	return (0);
}