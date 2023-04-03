/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/03 22:52:31 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *i)
{
	t_philos	*philo;

	philo = (t_philos *)i;
	philo->start = get_time();
	while (philo->pointer)
	{
		if (!(*philo->pointer))
			printf("%lld %d is thinking\n", curr_time(philo), philo->id);
		if (philo->id % 2 == 0)
		{
			taking_left_fork(philo);
			is_eating(philo);
		}
		else
		{
			taking_right_fork(philo);
			is_eating(philo);
		}
		if (!(*philo->pointer))
			printf("%lld %d is sleeping\n", curr_time(philo), philo->id);
		my_usleep(philo->time_to_sleep);
	}
	return (0);
}

int	join(t_philos *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (pthread_join(philo[i].philo, NULL) != 0)
			return (2);
		i++;
	}
	return (0);
}

int	creat_threads(t_philos *phil, int ac, char **av)
{
	int				i;

	i = 0;
	tasks(phil, ac, av);
	phil->fork = malloc(sizeof(pthread_mutex_t) * phil->number_of_philosophers);
	mutex(phil);
	make_info(phil);
	while (i < phil->number_of_philosophers)
	{
		if (pthread_create(&phil[i].philo, NULL, &routine, &phil[i]) != 0)
			return (1);
		usleep (500);
		i++;
	}
	if (check_time_of_death(phil))
		return (1);
	join(phil);
	return (1);
}
