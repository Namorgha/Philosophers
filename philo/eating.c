/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/16 12:38:29 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->data[0]);
	printf("%lld %d is eating\n", curr_time(philo), philo->id);
	pthread_mutex_unlock(&philo->data[0]);
	philo->ate++;
	pthread_mutex_lock(&philo->data[0]);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data[0]);
	my_usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork[philo->forkl]);
	pthread_mutex_unlock(&philo->fork[philo->forkr]);
}
