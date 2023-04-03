/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/03 13:23:10 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_left_fork(t_philos *philo)
{
	printf("the id == [%d]\n", philo->id);
	pthread_mutex_lock(&philo->fork[philo->forkl]);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_lock(&philo->fork[philo->forkr]);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
}

void	taking_right_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork[philo->forkr]);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
	pthread_mutex_lock(&philo->fork[philo->forkl]);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
}

void	is_eating(t_philos *philo)
{
	printf("%lld %d is eating\n", curr_time(philo), philo->id);
	philo->last_meal = get_time();
	my_usleep(philo->time_to_eat);
	philo->ate++;
	if (philo->ate == philo->number_of_times_each_philosopher_must_eat)
		philo->should_die++;
}

void	*timing(void *i)
{
	t_philos	*ph;

	ph = (t_philos *)i;
	ph->start = get_time();
	make_info(ph);
	while (1)
	{
		printf("%lld %d is thinking\n", curr_time(ph), ph->id);
		if (ph->id % 2 == 0)
		{
			taking_left_fork(ph);
			is_eating(ph);
			pthread_mutex_unlock(&ph->fork[ph->forkl]);
			pthread_mutex_unlock(&ph->fork[ph->forkr]);
		}
		else
		{
			taking_right_fork(ph);
			is_eating(ph);
			pthread_mutex_unlock(&ph->fork[ph->forkl]);
			pthread_mutex_unlock(&ph->fork[ph->forkr]);
		}
		printf("%lld %d is sleeping\n", curr_time(ph), ph->id);
		my_usleep(ph->time_to_sleep);
		if (ph->number_of_times_each_philosopher_must_eat != 0)
		{
			if (ph->should_die == ph->number_of_times_each_philosopher_must_eat)
				exit(1);
		}
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
	while (i < phil->number_of_philosophers)
	{
		if (pthread_create(&phil[i].philo, NULL, &timing, &phil[i]) != 0)
			return (1);
		usleep (10);
		i++;
	}

	if(check_time_of_death(phil) == 1)
		return (1);
	i = 0;
	while (i < phil->number_of_philosophers)
	{
		if (pthread_join(phil[i].philo, NULL) != 0)
			return (2);
		i++;
	}
	return (1);
}
