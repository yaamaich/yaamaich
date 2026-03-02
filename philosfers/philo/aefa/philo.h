/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:15:36 by sael-kha          #+#    #+#             */
/*   Updated: 2025/06/19 13:25:57 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	long long		last_time_eat;
	int				nbr_meals;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	struct s_table	*table;
}				t_philo;

typedef struct s_table
{
	long long		nbr_of_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		max_meals;
	long long		time_spend;
	int				end_of_simulation;
	int				philo_full;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	protect;
	pthread_mutex_t	print;
}				t_table;

long long	get_time(void);
void		*hayat(void	*arg);
long		ft_atol(char *str);
void		*hayat1(void *arg);
int			check_len(char *str);
int			check_int(char *str);
void		*check_death(void *arg);
void		too_late(t_philo *philo);
int			check_end(t_philo *philo);
void		check_full(t_philo *philo);
void		init_philo(t_table *table);
void		destroy_all(t_table *table);
void		precise_sleep(long long ms);
void		update_safe(t_philo *philo);
void		start_simulation(t_table *table);
void		ft_print_death(t_table *table, int i);
void		printf_status(t_philo *philo, char *status);
void		init_table(t_table *table, int ac, char **av);

#endif