/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:14 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/07 07:13:48 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_left_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork[philo->forkl]);
	pthread_mutex_lock(&philo->print);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->fork[philo->forkr]);
	pthread_mutex_lock(&philo->print);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_unlock(&philo->print);
}

void	taking_right_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork[philo->forkr]);
	pthread_mutex_lock(&philo->print);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_lock(&philo->fork[philo->forkl]);
	pthread_mutex_lock(&philo->print);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_unlock(&philo->print);
}
