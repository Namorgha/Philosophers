/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/28 14:35:46 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checlllll(t_philos *philo, int i)
{
	pthread_mutex_lock(&philo->data);
	if ((get_time() - philo[i].last_meal) >= \
			philo->time_to_die && philo->num_ate == 0)
		return (1);
	pthread_mutex_unlock(&philo->data);
	return (0);
}

int	check_time_of_death(t_philos *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			pthread_mutex_lock(&philo->dat);
			if (checlllll(philo, i))
			{
				usleep(1000);
				printf("%lld %d died\n", curr_time(philo), philo[i].id);
				return (1);
				pthread_mutex_lock(&philo->data);
				philo->died = 1;
				pthread_mutex_unlock(&philo->data);
				pthread_mutex_unlock(&philo->dat);
			}
			pthread_mutex_unlock(&philo->dat);
			i++;
		}
		if (philo->num_ate == 1)
			return (0);
	}
	return (0);
}
