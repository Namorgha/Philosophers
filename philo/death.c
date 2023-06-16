/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/16 12:34:08 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checlllll(t_philos *philo, int i)
{
	pthread_mutex_lock(&philo->data[0]);
	if ((get_time() - philo[i].last_meal) >= \
			philo->time_to_die)
	{
		pthread_mutex_unlock(&philo->data[0]);
		return (1);
	}
	pthread_mutex_unlock(&philo->data[0]);
	return (0);
}

int	check_eat(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (philo[i].num_ate == 1)
			i++;
	}
	if (i == philo->number_of_philosophers)
		return 1;
	return (0);
}

int	check_time_of_death(t_philos *philo)
{
	int	i;

	while (!(*philo->pointer))
	{
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			if (checlllll(philo, i))
			{
				pthread_mutex_lock(&philo->data[0]);
				printf("%lld %d died\n", curr_time(philo), philo[i].id);
				return (1);
			}
			i++;
		}
		if (philo->number_of_times_each_philosopher_must_eat != -1 \
				&& check_eat(philo))
			return (1);
	}
	return (0);
}
