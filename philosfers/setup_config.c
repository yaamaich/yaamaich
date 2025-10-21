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

long	ftatol(const char *s)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	get_digit_count(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

int	validate_numeric(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	setup_table(int ac, char **av, t_table *t)
{
	int		i;

	i = 0;
	t->philo_count = ftatol(av[1]);
	t->death_time = ftatol(av[2]);
	t->eating_time = ftatol(av[3]);
	t->sleeping_time = ftatol(av[4]);
	t->meals_required = -1;
	if (ac == 6)
		t->meals_required = ftatol(av[5]);
	t->simulation_stop = 0;
	t->full_philos = 0;
	t->philosophers = malloc(sizeof(t_philo) * t->philo_count);
	t->forks_array = malloc(sizeof(pthread_mutex_t) * t->philo_count);
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
