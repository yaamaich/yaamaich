/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:30:16 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 12:30:16 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	extract_digit(char c)
{
	return ((long)(c - '0'));
}

static long	multiply_by_ten(long num)
{
	return (num * 10);
}

long	ftatol(const char *s)
{
	long	accumulator;
	int		idx;
	long	single_digit;
	long	shifted;

	idx = 0;
	accumulator = 0;
	while (s[idx] != '\0')
	{
		single_digit = extract_digit(s[idx]);
		shifted = multiply_by_ten(accumulator);
		accumulator = shifted + single_digit;
		idx++;
	}
	return (accumulator);
}

static int	skip_leading_zeros(const char *s)
{
	int	pos;

	pos = 0;
	while (s[pos] == '0')
		pos++;
	return (pos);
}

static int	count_numeric_chars(const char *s, int start)
{
	int	counter;
	int	position;

	counter = 0;
	position = start;
	while (s[position] >= '0' && s[position] <= '9')
	{
		counter++;
		position++;
	}
	return (counter);
}

int	get_digit_count(const char *s)
{
	int	offset;
	int	total_digits;

	offset = skip_leading_zeros(s);
	total_digits = count_numeric_chars(s, offset);
	return (total_digits);
}

static int	is_digit_char(char c)
{
	int	lower_bound;
	int	upper_bound;

	lower_bound = (c >= '0');
	upper_bound = (c <= '9');
	return (lower_bound && upper_bound);
}

int	validate_numeric(const char *s)
{
	int		idx;
	char	current_char;
	int		is_valid_digit;

	idx = 0;
	while (s[idx])
	{
		current_char = s[idx];
		is_valid_digit = is_digit_char(current_char);
		if (!is_valid_digit)
			return (1);
		idx++;
	}
	return (0);
}

void	setup_table(int ac, char **av, t_table *t)
{
	int		i;
	size_t	philo_size;
	size_t	mutex_size;

	long	arg1;
	long	arg2;
	long	arg3;
	long	arg4;
	long	count;

	i = 0;
	arg1 = ftatol(av[1]);
	arg2 = ftatol(av[2]);
	arg3 = ftatol(av[3]);
	arg4 = ftatol(av[4]);
	t->philo_count = arg1;
	t->death_time = arg2;
	t->eating_time = arg3;
	t->sleeping_time = arg4;
	t->meals_required = -1;
	if (ac == 6)
		t->meals_required = ftatol(av[5]);
	t->simulation_stop = 0;
	t->full_philos = 0;
	count = t->philo_count;
	philo_size = sizeof(t_philo) * count;
	mutex_size = sizeof(pthread_mutex_t) * count;
	t->philosophers = malloc(philo_size);
	t->forks_array = malloc(mutex_size);
	while (i < count)
	{
		pthread_mutex_init(&t->forks_array[i], NULL);
		i++;
	}
	pthread_mutex_init(&t->write_lock, NULL);
}

static int	calculate_next_index(int current, long total)
{
	int	next_pos;
	int	total_count;

	total_count = (int)total;
	next_pos = (current + 1) % total_count;
	return (next_pos);
}

static void	assign_philosopher_id(t_philo *philo, int idx)
{
	int	id_value;

	id_value = idx + 1;
	philo->philo_id = id_value;
}

static void	assign_forks(t_philo *philo, pthread_mutex_t *forks, int idx, long total)
{
	int	next_idx;

	philo->fork_right = &forks[idx];
	next_idx = calculate_next_index(idx, total);
	philo->fork_left = &forks[next_idx];
}

void	setup_philosophers(t_table *t)
{
	int			idx;
	long		total;
	long long	init_time;

	idx = 0;
	total = t->philo_count;
	init_time = current_time();
	while (idx < total)
	{
		assign_philosopher_id(&t->philosophers[idx], idx);
		t->philosophers[idx].meals_count = 0;
		assign_forks(&t->philosophers[idx], t->forks_array, idx, total);
		t->philosophers[idx].data = t;
		t->philosophers[idx].last_meal_time = init_time;
		idx++;
	}
}
`