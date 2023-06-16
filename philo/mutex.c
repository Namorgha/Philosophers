/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:15 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/12 09:09:37 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex(t_philos *ph)
{
	int	j;

	j = 0;
	pthread_mutex_init(&ph->data[0], NULL);
	while (j < ph->number_of_philosophers)
	{
		pthread_mutex_init(&ph->fork[j], NULL);
		j++;
	}
}
