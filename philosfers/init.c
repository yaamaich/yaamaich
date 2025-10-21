/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:30:16 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 04:30:16 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	string_to_long(const char *str)
{
	long	result;
	int		index;

	index = 0;
	result = 0;
	while (str[index])
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result);
}

int	get_digit_count(const char *str)
{
	int	cursor;
	int	digit_len;

	cursor = 0;
	digit_len = 0;
	while (str[cursor] == '0')
		cursor++;
	while (str[cursor] >= '0' && str[cursor] <= '9')
	{
		digit_len++;
		cursor++;
	}
	return (digit_len);
}

int	validate_numeric(const char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
	{
		if (str[iter] < '0' || str[iter] > '9')
			return (1);
		iter++;
	}
	return (0);
}
void	setup_table(int argc, char **argv, t_table *table)
{
	int	counter;

	counter = 0;
	table->philo_count = string_to_long(argv[1]);
	table->death_time = string_to_long(argv[2]);
	table->eating_time = string_to_long(argv[3]);
	table->sleeping_time = string_to_long(argv[4]);
	table->meals_required = -1;
	if (argc == 6)
		table->meals_required = string_to_long(argv[5]);
	table->simulation_stop = 0;
	table->full_philos = 0;
	table->philosophers = malloc(sizeof(t_philo) * table->philo_count);
	table->forks_array = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	while (counter < table->philo_count)
		pthread_mutex_init(&table->forks_array[counter++], NULL);
	pthread_mutex_init(&table->write_lock, NULL);
}

void	setup_philosophers(t_table *table)
{
	int	position;

	position = 0;
	while (position < table->philo_count)
	{
		table->philosophers[position].philo_id = position + 1;
		table->philosophers[position].meals_count = 0;
		table->philosophers[position].fork_right = &table->forks_array[position];
		table->philosophers[position].fork_left = &table->forks_array[(position + 1)
			% table->philo_count];
		table->philosophers[position].data = table;
		table->philosophers[position].last_meal_time = current_time();
		position++;
	}
}