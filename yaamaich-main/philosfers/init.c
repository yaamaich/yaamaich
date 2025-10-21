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

int	get_digit_count(const char *str)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx] == '0')
		idx++;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		count++;
		idx++;
	}
	return (count);
}

int	validate_numeric(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (1);
		idx++;
	}
	return (0);
}

long	parse_long(const char *str)
{
	long	value;
	int		idx;

	value = 0;
	idx = 0;
	while (str[idx])
	{
		value = value * 10 + (str[idx] - '0');
		idx++;
	}
	return (value);
}
void	setup_data(int argc, char **argv, t_data *data)
{
	int	counter;

	counter = 0;
	data->num_philosophers = parse_long(argv[1]);
	data->death_time = parse_long(argv[2]);
	data->eat_time = parse_long(argv[3]);
	data->sleep_time = parse_long(argv[4]);
	data->required_meals = -1;
	if (argc == 6)
		data->required_meals = parse_long(argv[5]);
	data->simulation_end = 0;
	data->full_philosophers = 0;
	data->philosophers = malloc(sizeof(t_philosopher)
			* data->num_philosophers);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	while (counter < data->num_philosophers)
	{
		pthread_mutex_init(&data->forks[counter], NULL);
		counter++;
	}
	pthread_mutex_init(&data->write_lock, NULL);
}

void	setup_philosophers(t_data *data)
{
	int	idx;

	idx = 0;
	while (idx < data->num_philosophers)
	{
		data->philosophers[idx].philosopher_id = idx + 1;
		data->philosophers[idx].meals_eaten = 0;
		data->philosophers[idx].fork_right = &data->forks[idx];
		data->philosophers[idx].fork_left = &data->forks[(idx + 1)
			% data->num_philosophers];
		data->philosophers[idx].data = data;
		data->philosophers[idx].last_meal_time = get_current_time();
		idx++;
	}
}