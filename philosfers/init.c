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

long	ft_atol(const char *str)
{
	long result;
	int i;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 +(str[i] - '0');
		i++;
	}
	return (result);
}

int	check_len(const char *str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j++;
		i++;
	}
	return (j);
}
int	check_int(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
void	init_table(int argc, const char *str, t_table *table)
{
	int i = 0;

	i = 0;
	table->nbr_of_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->max_meals = -1;
	if (argc == 6)
		table->max_meals = ft_atol(argv[5]);
	table->end_of_simulation = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philo);
	while (i < table->nbr_of_philo)
		pthread_mutex_init(&table->forks[i++], NULL);
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->protect, NULL);
	}
	void 	init_philo(t_table *table)
	{
		int i;

		i = 0;
		while ( i < table->nbr_of_philo)
		{
			table->philos[i].id = i + 1;
			table->philos[i].nbr_meals = 0;
			table->philos[i].right_fork = &table->forks[i];
			table->philos[i].left_fork = &table->forks[(i + 1)
				% table->nbr_of_philo];
			table->philos[i].table = &table;
			table->philos[i].last_time_eat = get_time();
			i++;
		}
	}