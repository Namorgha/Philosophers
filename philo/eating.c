/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/23 14:22:22 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->dat);
	if (!(*philo->pointer))
	{
		pthread_mutex_unlock(&philo->dat);
		pthread_mutex_lock(&philo->print);
		printf("%lld %d is eating\n", curr_time(philo), philo->id);
		pthread_mutex_unlock(&philo->print);
		pthread_mutex_lock(&philo->dat);
	}
	philo->last_meal = get_time();
	philo->ate++;
	pthread_mutex_unlock(&philo->dat);
	my_usleep(philo->time_to_eat);
	pthread_mutex_lock(&philo->data);
	pthread_mutex_unlock(&philo->data);
	pthread_mutex_unlock(&philo->fork[philo->forkl]);
	pthread_mutex_unlock(&philo->fork[philo->forkr]);
}
