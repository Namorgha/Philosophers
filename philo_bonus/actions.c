/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:30:22 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/28 12:34:13 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	put_th_fork_down(t_philos *philo)
{
	sem_post(philo->fork);
	sem_post(philo->fork);
}

void	thinking(t_philos *philo)
{
	if (!(*philo->pointer))
		printf("%lld %d is thinking\n", curr_time(philo), philo->id);
}

void	take_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
}

void	sleeping(t_philos *philo)
{
	if (!(*philo->pointer))
		printf("%lld %d is sleeping\n", curr_time(philo), philo->id);
	my_usleep(philo->time_to_sleep);
}
