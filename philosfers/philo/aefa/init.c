/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:47:51 by sael-kha          #+#    #+#             */
/*   Updated: 2025/06/19 13:26:47 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j++;
		i++;
	}
	return (j);
}

void	init_table(t_table *table, int ac, char **av)
{
	int	i;

	i = 0;
	table->nbr_of_philo = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->max_meals = -1;
	if (ac == 6)
		table->max_meals = ft_atol(av[5]);
	table->end_of_simulation = 0;
	table->philo_full = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philo);
	while (i < table->nbr_of_philo)
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->protect, NULL);
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].last_time_eat = get_time();
		table->philos[i].nbr_meals = 0;
		table->philos[i].right_fork = &table->forks[(i + 1)
			% table->nbr_of_philo];
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].table = table;
		i++;
	}
}
