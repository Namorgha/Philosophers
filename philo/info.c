/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:30 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/28 13:54:24 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_info(t_philos *philo)
{
	int	i;

	i = 0;
	philo->died = 0;
	pthread_mutex_lock(&philo->data);
	while (i < philo->number_of_philosophers)
	{
		philo[i].fork = philo->fork;
		philo[i].print = philo->print;
		philo[i].id = i + 1;
		philo[i].forkl = i;
		philo[i].forkr = (i + 1) % philo->number_of_philosophers;
		philo[i].last_meal = get_time();
		philo[i].should_die = 0;
		philo->num_ate = 0;
		philo[i].pointer = &philo->died;
		philo[i].ate = 0;
		i++;
	}
	pthread_mutex_unlock(&philo->data);
}
