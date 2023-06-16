/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/16 12:28:13 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *i)
{
	t_philos	*philo;

	philo = (t_philos *)i;
	while (1)
	{
		pthread_mutex_lock(&philo->data[0]);
		printf("%lld %d is thinking\n", curr_time(philo), philo->id);
		pthread_mutex_unlock(&philo->data[0]);
		taking_left_fork(philo);
		is_eating(philo);
		check_d(philo);
		pthread_mutex_lock(&philo->data[0]);
		printf("%lld %d is sleeping\n", curr_time(philo), philo->id);
		pthread_mutex_unlock(&philo->data[0]);
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
			return (1);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&philo->data[0]);
	while (i < philo->number_of_philosophers)
		pthread_mutex_destroy(&philo->fork[i++]);
	return (0);
}

int	creat_threads(t_philos *phil, int ac, char **av)
{
	int				i;

	i = 0;
	tasks(phil, ac, av);
	if (check_error(phil, ac, av))
		return (0);
	phil->fork = malloc(sizeof(pthread_mutex_t) * phil->number_of_philosophers);
	phil->data = malloc(sizeof(pthread_mutex_t) * 1);
	mutex(phil);
	make_info(phil);
	while (i < phil->number_of_philosophers)
	{
		if (pthread_create(&phil[i].philo, NULL, &routine, &phil[i]) != 0)
			return (1);
		usleep(50);
		i++;
	}
	if (!check_time_of_death(phil))
	{
		join(phil);
		return (1);
	}
	return (1);
}
