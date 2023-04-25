/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 11:56:45 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_eating(t_philos *philo)
{
	if (!(*philo->pointer))
	{
		sem_wait(philo->print);
		printf("%lld %d is eating\n", curr_time(philo), philo->id);
		sem_post(philo->print);
	}
	philo->ate++;
	philo->last_meal = get_time();
	my_usleep(philo->time_to_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
}
