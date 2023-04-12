/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/12 01:47:55 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_time_of_death(void *j)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)j;
	while (!philo->died)
	{
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			if ((philo->last_meal + philo->time_to_die) < get_time())
			{
				if (!philo->died)
					printf("%lld %d died\n", curr_time(philo), philo[i].id);
				exit(1);
			}
			i++;
		}
	}
	return (0);
}
