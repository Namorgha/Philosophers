/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 09:24:43 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philos *philo)
{
	if (!(*philo->pointer))
		printf("%lld %d is eating\n", curr_time(philo), philo->id);
	philo->ate++;
	philo->last_meal = get_time();
	my_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork[philo->forkl]);
	pthread_mutex_unlock(&philo->fork[philo->forkr]);
}
