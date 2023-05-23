/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/23 14:37:29 by namorgha         ###   ########.fr       */
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
			if ((get_time() - philo->last_meal) >= philo[i].time_to_die)
			{
				philo->died = 1;
				usleep(500);
				printf("%lld %d died\n", curr_time(philo), philo->id);
				return (1);
			}
			i++;
		}
		if (philo->num_ate == 1)
			return (0);
	}
	return (0);
}
