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

static void	lock_table_mutex(t_philo *p)
{
	pthread_mutex_lock(&p->data->write_lock);
}

static void	unlock_table_mutex(t_philo *p)
{
	pthread_mutex_unlock(&p->data->write_lock);
}

static void	record_meal_time(t_philo *p)
{
	long long	now;

	now = current_time();
	p->last_meal_time = now;
}

static void	increment_meal_counter(t_philo *p)
{
	int	current;
	int	next;

	current = p->meals_count;
	next = current + 1;
	p->meals_count = next;
}

void	update_meal_status(t_philo *p)
{
	lock_table_mutex(p);
	record_meal_time(p);
	increment_meal_counter(p);
	unlock_table_mutex(p);
}

void	philo_sleep_routine(t_philo *p)
{
	char		*msg;
	long long	duration;

	msg = "is sleeping";
	log_action(p, msg);
	duration = p->data->sleeping_time;
	ft_usleep(duration, p);
}

static int	reached_meal_limit(int current, int required)
{
	int	is_limited;
	int	matches;

	is_limited = (required != -1);
	matches = (current == required);
	return (is_limited && matches);
}

void	check_philo_fullness(t_philo *p)
{
	int	required_meals;
	int	current_meals;
	int	is_full;

	pthread_mutex_lock(&p->data->write_lock);
	required_meals = p->data->meals_required;
	current_meals = p->meals_count;
	is_full = reached_meal_limit(current_meals, required_meals);
	if (is_full)
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
