/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:02:05 by sael-kha          #+#    #+#             */
/*   Updated: 2025/04/15 20:40:27 by sael-kha         ###   ########.fr       */
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
	pthread_mutex_destroy(&table->print);
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

void	printf_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->table->protect);
	if (!philo->table->end_of_simulation)
	{
		printf("%lld %d %s\n", get_time() - philo->table->time_spend,
			philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->protect);
}

void	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (philo->table->max_meals != -1 && 
		philo->nbr_meals == philo->table->max_meals)
		philo->table->philo_full++;
	pthread_mutex_unlock(&philo->table->protect);
}

int	check_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->protect);
	if (philo->table->end_of_simulation)
	{
		pthread_mutex_unlock(&philo->table->protect);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->protect);
	return (0);
}
