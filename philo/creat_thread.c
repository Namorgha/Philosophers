/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/23 14:24:47 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *i)
{
	t_philos	*philo;

	philo = (t_philos *)i;
	pthread_mutex_lock(&philo->dat);
	philo->start = get_time();
	while (!(*philo->pointer))
	{
		pthread_mutex_unlock(&philo->dat);
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
		if (check_d(philo))
			return (0);
		if (!(*philo->pointer))
			printf("%lld %d is sleeping\n", curr_time(philo), philo->id);
		my_usleep(philo->time_to_sleep);
		pthread_mutex_lock(&philo->dat);
	}
	pthread_mutex_unlock(&philo->dat);
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
	pthread_mutex_destroy(&philo->data);
	pthread_mutex_destroy(&philo->death);
	pthread_mutex_destroy(&philo->dat);
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
	mutex(phil);
	make_info(phil);
	while (i < phil->number_of_philosophers)
	{
		if (pthread_create(&phil[i].philo, NULL, &routine, &phil[i]) != 0)
			return (1);
		i++;
	}
	if (check_time_of_death(phil))
		return (1);
	return (1);
}
