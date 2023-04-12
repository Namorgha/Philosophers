/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:13:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/12 01:55:59 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_eating(t_philos *philo)
{
	if (!(*philo->pointer))
		printf("%lld %d is eating\n", curr_time(philo), philo->id);
	philo->ate++;
	philo->last_meal = get_time();
	my_usleep(philo->time_to_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
}
