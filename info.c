/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:25:30 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/03 12:26:42 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_info(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		philo[i].fork = philo->fork;
		philo[i].id = i + 1;
		philo[i].forkl = i;
		philo[i].forkr = (i + 1) % philo->number_of_philosophers;
		philo[i].last_meal = get_time();
		philo->should_die = 0;
		philo[i].ate = 0;
		i++;
	}
}
