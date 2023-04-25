/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:28:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 17:33:58 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	*check_time_of_death(void *j)
// {
// 	t_philos	*philo;
// 	int			i;

// 	philo = (t_philos *)j;
// 	while (!(*philo->pointer))
// 	{
// 		i = 0;
// 		while (i < philo->number_of_philosophers)
// 		{
// 			if ((get_time() - philo->last_meal) > philo->time_to_die)
// 			{
// 				if (!(*philo->pointer))
// 					printf("%lld %d died\n", curr_time(philo), philo->id);
// 				philo->died = 1;
// 				exit(1);
// 			}
// 			i++;
// 		}
// 	}
// 	return (0);
// }


void	*check_time_of_death(void *j)
{
	t_philos	*philo;

	philo = (t_philos *)j;
	while (1)
	{
		if ((philo->last_meal + philo->time_to_die) < get_time())
		{
				if (!(*philo->pointer))
					printf("%lld %d died\n", curr_time(philo), philo->id);
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}
