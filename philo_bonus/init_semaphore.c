/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:46:34 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 10:11:30 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_philos *philo)
{
	int	i;

	i = 1;
	sem_unlink("/fork");
	philo[0].fork = sem_open("/fork", O_CREAT | O_EXCL, 0644, \
		philo->number_of_philosophers);
	while (i < philo->number_of_philosophers)
	{
		philo[i].fork = philo[0].fork;
		i++;
	}
	sem_unlink("/print");
	philo[0].print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	i = 1;
	while (i < philo->number_of_philosophers)
	{
		philo[i].print = philo[0].print;
		i++;
	}
}
