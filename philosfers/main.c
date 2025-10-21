/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:30:24 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 04:30:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	philo->last_meal_time = current_time();
	philo->meals_count++;
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	philo_sleep_routine(t_philo *philo)
{
	log_action(philo, "is sleeping");
	ft_usleep(philo->data->sleeping_time);
}

void	check_philo_fullness(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->meals_count != -1
		&& philo->meals_count == philo->data->meals_required)
		philo->data->full_philos++;
	pthread_mutex_unlock(&philo->data->write_lock);
}
static int	validate_arguments(int count, char **args)
{
	int		param_idx;
	long	num_value;

	param_idx = 1;
	while (param_idx < count)
	{
		num_value = string_to_long(args[param_idx]);
		if (!args[param_idx][0] || validate_numeric(args[param_idx])
			|| get_digit_count(args[param_idx]) > 10
			|| num_value < INT_MIN || num_value > INT_MAX || num_value == 0)
		{
			write(2, "Error: Invalid arguments\n", 25);
			write(2, "Please provide positive numbers only\n", 37);
			return (0);
		}
		param_idx++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (write(2, "Error: Wrong number of arguments\n", 33), 1);
	if (!validate_arguments(ac, av))
		return (1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	setup_table(ac, av, table);
	setup_philosophers(table);
	start_simulation(table);
	cleanup_resources(table);
	return (0);
}
