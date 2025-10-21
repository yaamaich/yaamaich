/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:35:24 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 04:35:24 by yaamaich         ###   ########.fr       */
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

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				philo_id;
	long long		last_meal_time;
	int				meals_count;
	pthread_t		philo_thread;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_table			*data;
}	t_philo;

typedef struct s_table
{
	long long		philo_count;
	long long		death_time;
	long long		eating_time;
	long long		sleeping_time;
	long long		meals_required;
	long long		start_time;
	int				simulation_stop;
	int				full_philos;
	t_philo			*philosophers;
	pthread_mutex_t	*forks_array;
	pthread_mutex_t	write_lock;
}	t_table;

long long	current_time(void);
void		*philosopher_routine(void *args);
void		*single_philo_routine(void *arg);
void		cleanup_resources(t_table *table);
void		*monitor_death(void *arg);
long		string_to_long(const char *str);
void		philo_sleep_routine(t_philo *philo);
int			is_simulation_over(t_philo *philo);
void		update_meal_status(t_philo *philo);
void		check_philo_fullness(t_philo *philo);
int			validate_numeric(const char *str);
int			get_digit_count(const char *str);
void		setup_philosophers(t_table *table);
void		start_simulation(t_table *table);
void		ft_usleep(long long ms);
void		announce_death(int philo_index, t_table *table);
void		log_action(t_philo *philo, char *status);
void		setup_table(int argc, char **argv, t_table *table);
#endif