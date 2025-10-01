/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 05:29:50 by yaamaich          #+#    #+#             */
/*   Updated: 2025/09/30 05:29:50 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long	get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->table->protect);
	if (!philo->table->end_of_simulation)
	{
		printf("%lld, %d, %s\n", get_time() - philo->table->time_spend, 
			philo->id, status);
	}
	pthread_mutex_unlock(philo->table->protect);
}