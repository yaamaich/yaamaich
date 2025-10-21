/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:30:24 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 12:30:24 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_status(t_philo *p)
{
	pthread_mutex_lock(&p->data->write_lock);
	p->last_meal_time = current_time();
	p->meals_count = p->meals_count + 1;
	pthread_mutex_unlock(&p->data->write_lock);
}

void	philo_sleep_routine(t_philo *p)
{
	log_action(p, "is sleeping");
	ft_usleep(p->data->sleeping_time, p);
}

void	check_philo_fullness(t_philo *p)
{
	int	req;
	int	curr;

	pthread_mutex_lock(&p->data->write_lock);
	req = p->data->meals_required;
	curr = p->meals_count;
	if (req != -1 && curr == req)
		p->data->full_philos++;
	pthread_mutex_unlock(&p->data->write_lock);
}

static int	validate_arguments(int cnt, char **args)
{
	int		i;
	long	val;
	int		digit_cnt;
	int		is_valid;

	i = 1;
	while (i < cnt)
	{
		val = ftatol(args[i]);
		digit_cnt = get_digit_count(args[i]);
		is_valid = validate_numeric(args[i]);
		if (!args[i][0] || is_valid || digit_cnt > 10)
		{
			write(2, "Error: Invalid arguments\n", 25);
			return (0);
		}
		if (val < INT_MIN || val > INT_MAX || val == 0)
		{
			write(2, "Error: Invalid arguments\n", 25);
			write(2, "Please provide positive numbers only\n", 37);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_table	*tbl;
	int		args_valid;

	if (ac < 5 || ac > 6)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	args_valid = validate_arguments(ac, av);
	if (!args_valid)
		return (1);
	tbl = malloc(sizeof(t_table));
	if (!tbl)
		return (1);
	setup_table(ac, av, tbl);
	setup_philosophers(tbl);
	start_simulation(tbl);
	cleanup_resources(tbl);
	return (0);
}
