/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/16 12:42:45 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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


void	*check_time_of_death(void *j)
{
	t_philos	*philo;

	philo = (t_philos *)j;
	while (1)
	{
		if ((get_time() - philo->last_meal) >= philo->time_to_die)
		{
			if (!(*philo->pointer))
			{
				usleep(100);
				philo->died = 1;
				sem_wait(philo->print);
				printf("%lld %d died\n", curr_time(philo), philo->id);
			}
			exit(1);
		}
		if (philo->number_of_times_each_philosopher_must_eat != -1 \
			&& check_eat(philo))
			exit(0);
	}
	return (NULL);
}
