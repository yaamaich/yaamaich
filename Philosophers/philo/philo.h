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
void		cleanup_resources(t_table *t);
void		*monitor_death(void *arg);
long		ftatol(const char *s);
void		philo_sleep_routine(t_philo *p);
int			is_simulation_over(t_philo *p);
void		update_meal_status(t_philo *p);
void		check_philo_fullness(t_philo *p);
int			validate_numeric(const char *s);
int			get_digit_count(const char *s);
void		setup_philosophers(t_table *t);
void		start_simulation(t_table *t);
void		ft_usleep(long long t, t_philo *p);
void		announce_death(int i, t_table *t);
void		log_action(t_philo *p, char *msg);
int			check_death_condition(t_table *t, int i);
void		setup_table(int ac, char **av, t_table *t);
#endif