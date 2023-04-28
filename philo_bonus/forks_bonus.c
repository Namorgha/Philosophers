/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:14 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/26 15:29:26 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_left_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	if (!(*philo->pointer))
	{
		sem_wait(philo->print);
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
		sem_post(philo->print);
	}
	sem_wait(philo->fork);
	if (!(*philo->pointer))
	{
		sem_wait(philo->print);
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
		sem_post(philo->print);
	}
}

void	taking_right_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	if (!(*philo->pointer))
	{
		sem_wait(philo->print);
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
		sem_post(philo->print);
	}
	sem_wait(philo->fork);
	if (!(*philo->pointer))
	{
		sem_wait(philo->print);
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
		sem_post(philo->print);
	}
}
