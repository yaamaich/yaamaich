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

long	string_to_long(const char *s)
{
	long	res;
	int		i;
	int		digit;

	i = 0;
	res = 0;
	while (s[i])
	{
		digit = s[i] - '0';
		res = res * 10 + digit;
		i++;
	}
	return (res);
}

int	get_digit_count(const char *s)
{
	int	i;
	int	len;
	int	c;

	i = 0;
	len = 0;
	while (s[i] == '0')
		i++;
	c = i;
	while (s[c] >= '0' && s[c] <= '9')
	{
		len++;
		c++;
	}
	return (len);
}

int	validate_numeric(const char *s)
{
	int	i;
	int	ch;

	i = 0;
	while (s[i])
	{
		ch = s[i];
		if (ch < '0' || ch > '9')
			return (1);
		i++;
	}
	return (0);
}

void	setup_table(int ac, char **av, t_table *t)
{
	int		i;
	size_t	philo_size;
	size_t	mutex_size;

	i = 0;
	t->philo_count = string_to_long(av[1]);
	t->death_time = string_to_long(av[2]);
	t->eating_time = string_to_long(av[3]);
	t->sleeping_time = string_to_long(av[4]);
	t->meals_required = -1;
	if (ac == 6)
		t->meals_required = string_to_long(av[5]);
	t->simulation_stop = 0;
	t->full_philos = 0;
	philo_size = sizeof(t_philo) * t->philo_count;
	mutex_size = sizeof(pthread_mutex_t) * t->philo_count;
	t->philosophers = malloc(philo_size);
	t->forks_array = malloc(mutex_size);
	while (i < t->philo_count)
	{
		pthread_mutex_init(&t->forks_array[i], NULL);
		i++;
	}
	pthread_mutex_init(&t->write_lock, NULL);
}

void	setup_philosophers(t_table *t)
{
	int	i;
	int	next;

	i = 0;
	while (i < t->philo_count)
	{
		t->philosophers[i].philo_id = i + 1;
		t->philosophers[i].meals_count = 0;
		t->philosophers[i].fork_right = &t->forks_array[i];
		next = (i + 1) % t->philo_count;
		t->philosophers[i].fork_left = &t->forks_array[next];
		t->philosophers[i].data = t;
		t->philosophers[i].last_meal_time = current_time();
		i++;
	}
}
