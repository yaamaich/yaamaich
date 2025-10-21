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

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_philosopher
{
	int				philosopher_id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		life_thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			*data;
}	t_philosopher;

typedef struct s_data
{
	long long		num_philosophers;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	long long		start_time;
	long long		required_meals;
	int				simulation_end;
	int				full_philosophers;
	t_philosopher	*philosophers;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
}	t_data;

long long	get_current_time(void);
void		precise_sleep(long long milliseconds);
void		*philosopher_routine(void *arg);
void		*single_philo_routine(void *arg);
void		*monitor_routine(void *arg);
void		start_simulation(t_data *data);
void		setup_data(int argc, char **argv, t_data *data);
void		setup_philosophers(t_data *data);
void		cleanup_resources(t_data *data);
void		display_status(t_philosopher *philo, char *msg);
void		display_death(int index, t_data *data);
void		update_meal_status(t_philosopher *philo);
void		perform_sleep(t_philosopher *philo);
void		verify_completion(t_philosopher *philo);
int			is_simulation_over(t_philosopher *philo);
int			validate_numeric(const char *str);
int			get_digit_count(const char *str);
long		parse_long(const char *str);

#endif