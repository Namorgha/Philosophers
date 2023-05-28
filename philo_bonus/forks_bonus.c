/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:14 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/24 23:47:58 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	taking_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	sem_wait(philo->fork);
	if (!(*philo->pointer))
		printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
}
