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

void	verify_completion(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->meals_eaten != -1
		&& philo->meals_eaten == philo->data->required_meals)
		philo->data->full_philosophers++;
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	perform_sleep(t_philosopher *philo)
{
	display_status(philo, "is sleeping");
	precise_sleep(philo->data->sleep_time);
}

void	update_meal_status(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->write_lock);
}
int	main(int ac, char **av)
{
	t_data	*data;
	int		idx;
	long	value;

	if (ac < 5 || ac > 6)
		return (1);
	idx = 1;
	while (idx < ac)
	{
		value = parse_long(av[idx]);
		if (!av[idx][0] || validate_numeric(av[idx])
			|| get_digit_count(av[idx]) > 10
			|| value < INT_MIN || value > INT_MAX || value == 0)
		{
			write(2, "are uu sure ab what uu inter?", 30);
			write(2, "make sure all numbers and positive!!\n", 38);
			return (1);
		}
		idx++;
	}
	data = malloc(sizeof(t_data));
	setup_data(ac, av, data);
	setup_philosophers(data);
	start_simulation(data);
	cleanup_resources(data);
	return (0);
}
