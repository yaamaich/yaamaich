/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:19:46 by yaamaich          #+#    #+#             */
/*   Updated: 2025/10/21 12:19:46 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_fork_mutexes(pthread_mutex_t *forks, long count)
{
	int		idx;
	long	total;

	idx = 0;
	total = count;
	while (idx < total)
	{
		pthread_mutex_destroy(&forks[idx]);
		idx++;
	}
}

static void	free_allocated_memory(t_table *t)
{
	free(t->forks_array);
	free(t->philosophers);
	free(t);
}

void	cleanup_resources(t_table *t)
{
	long	philo_count;

	philo_count = t->philo_count;
	destroy_fork_mutexes(t->forks_array, philo_count);
	pthread_mutex_destroy(&t->write_lock);
	free_allocated_memory(t);
}

static long long	convert_seconds_to_ms(long seconds)
{
	long long	milliseconds;

	milliseconds = (long long)seconds * 1000;
	return (milliseconds);
}

static long long	convert_microseconds_to_ms(long microseconds)
{
	long long	milliseconds;

	milliseconds = (long long)microseconds / 1000;
	return (milliseconds);
}

long long	current_time(void)
{
	struct timeval	tv;
	long long		sec_in_ms;
	long long		usec_in_ms;
	long long		total_ms;

	gettimeofday(&tv, NULL);
	sec_in_ms = convert_seconds_to_ms(tv.tv_sec);
	usec_in_ms = convert_microseconds_to_ms(tv.tv_usec);
	total_ms = sec_in_ms + usec_in_ms;
	return (total_ms);
}

static int	check_simulation_status(t_philo *p)
{
	int	stop_flag;

	stop_flag = p->data->simulation_stop;
	return (stop_flag);
}

static long long	calculate_elapsed_time(t_philo *p)
{
	long long	now;
	long long	start;
	long long	elapsed;

	now = current_time();
	start = p->data->start_time;
	elapsed = now - start;
	return (elapsed);
}

void	log_action(t_philo *p, char *msg)
{
	long long	elapsed_time;
	int			philosopher_id;
	int			stop_flag;

	pthread_mutex_lock(&p->data->write_lock);
	stop_flag = check_simulation_status(p);
	if (!stop_flag)
	{
		elapsed_time = calculate_elapsed_time(p);
		philosopher_id = p->philo_id;
		printf("%lld %d %s\n", elapsed_time, philosopher_id, msg);
	}
	pthread_mutex_unlock(&p->data->write_lock);
}

static void	set_stop_flag(t_table *t)
{
	t->simulation_stop = 1;
}

static long long	compute_death_timestamp(t_table *t)
{
	long long	now;
	long long	start;
	long long	timestamp;

	now = current_time();
	start = t->start_time;
	timestamp = now - start;
	return (timestamp);
}

void	announce_death(int i, t_table *t)
{
	long long	death_time;
	int			dead_philo_id;

	set_stop_flag(t);
	death_time = compute_death_timestamp(t);
	dead_philo_id = t->philosophers[i].philo_id;
	printf("%lld %d died\n", death_time, dead_philo_id);
	pthread_mutex_unlock(&t->write_lock);
}

static int	read_stop_flag(t_philo *p)
{
	int	flag_value;

	pthread_mutex_lock(&p->data->write_lock);
	flag_value = p->data->simulation_stop;
	pthread_mutex_unlock(&p->data->write_lock);
	return (flag_value);
}

int	is_simulation_over(t_philo *p)
{
	int	stop_flag;

	stop_flag = read_stop_flag(p);
	if (stop_flag)
		return (1);
	return (0);
}
