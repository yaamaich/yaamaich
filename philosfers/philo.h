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
#define PHILO_H

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
    struct S_table *table;
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
    pthread_mutex_t print;
}               t_table;

int     ft_atol(const char *str);
int     check_int(const char *str);
int     check_len(const char *str);
void    init_table(t_table *table);
void    init_philo(t_table *table);
void    simolation(t_table *table);


#endif