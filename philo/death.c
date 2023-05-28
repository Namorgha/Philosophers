/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/28 12:19:09 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time_of_death(t_philos *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			pthread_mutex_lock(&philo->dat);
			if ((philo[i].last_meal + philo->time_to_die) <= get_time())
			{
				philo->died = 1;
				usleep(500);
				pthread_mutex_lock(&philo->print);
				printf("%lld %d died\n", curr_time(philo), philo->id);
				pthread_mutex_unlock(&philo->print);
				pthread_mutex_unlock(&philo->dat);
				return (1);
			}
			pthread_mutex_unlock(&philo->dat);
			i++;
		}
		pthread_mutex_lock(&philo->dat);
		if (philo->num_ate == 1)
		{
			pthread_mutex_unlock(&philo->dat);
			return (0);
		}
		pthread_mutex_unlock(&philo->dat);
	}
	return (0);
}


