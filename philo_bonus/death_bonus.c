/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 20:55:08 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_time_of_death(void *j)
{
	t_philos	*philo;

	philo = (t_philos *)j;
	while (1)
	{
		if (philo->num_ate == 1)
			exit(0);
		if ((philo->last_meal + philo->time_to_die) < get_time())
		{
			if (!(*philo->pointer))
			{
				sem_wait(philo->print);
				printf("%lld %d died\n", curr_time(philo), philo->id);
				philo->died = 1;
			}
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}
