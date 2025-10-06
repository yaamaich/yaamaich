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

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct      s_philo
{
	int             id;
	long long       last_time_eat;
	int             nbr_meals;
	pthread_t       thread;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	struct s_table *table;
}                   t_philo;

typedef struct s_table
{
	long long   nbr_of_philo;
	long long   time_to_die;
	long long   time_to_eat;
	long long   time_to_sleep;
	long long   max_meal;
	long long   time_spend;
	int         end;
	int         philo_full;
	t_philo     *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t protect;
}               t_table;

long long	get_time(void);
void		*lifes(void *args);
void		*one_life(void *arg);
void		destroy_all(t_table *table);
void		*check_death(void *arg);
long		ft_atol(const char *str);
void		too_late(t_philo *philo);
int			check_end(t_philo *philo);
void		philo_safe(t_philo *philo);
void		check_full(t_philo *philo);
int			check_int(const char *str);
int			check_len(const char *str);
void		init_philo(t_table *table);
void		simulation(t_table *table);
void		precise_sleep(long long ms);
void		print_death(int i, t_table *table);
void		print_status(t_philo *philo, char *status);
void		init_table(int argc, char **argv, t_table *table);
#endif