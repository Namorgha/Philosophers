/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/02 15:52:30 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	mutex(t_philos *ph)
{
	int				j;

	j = 0;
	while (j < ph->number_of_philosophers)
	{
		pthread_mutex_init(&ph->fork[j], NULL);
		j++;
	}
}

void	my_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(50);
}

long long	curr_time(t_philos *philo)
{
	return (get_time() - philo->start);
}

void	*timing(void *i)
{
	t_philos	*ph;

	ph = (t_philos *)i;
	ph->start = get_time();
	while (1)
	{
		printf("%lld %d is thinking\n", curr_time(ph), ph->id);
		if (ph->id % 2 == 0)
		{
			pthread_mutex_lock(&ph->fork[ph->forkl]);
			printf("%lld %d has taken a fork\n", curr_time(ph), ph->id);
			pthread_mutex_lock(&ph->fork[ph->forkr]);
			printf("%lld %d has taken a fork\n", curr_time(ph), ph->id);
			printf("%lld %d is eating\n", curr_time(ph), ph->id);
			ph->last_meal = get_time();
			my_usleep(ph->time_to_eat);
			ph->ate++;
			if (ph->ate == ph->number_of_times_each_philosopher_must_eat)
				exit(1);
			pthread_mutex_unlock(&ph->fork[ph->forkl]);
			pthread_mutex_unlock(&ph->fork[ph->forkr]);
		}
		else
		{
			pthread_mutex_lock(&ph->fork[ph->forkr]);
			printf("%lld %d has taken a fork\n", curr_time(ph), ph->id);
			pthread_mutex_lock(&ph->fork[ph->forkl]);
			printf("%lld %d has taken a fork\n", curr_time(ph), ph->id);
			printf("%lld %d is eating\n", curr_time(ph), ph->id);
			ph->last_meal = get_time();
			my_usleep(ph->time_to_eat);
			ph->ate++;
			if (ph->ate == ph->number_of_times_each_philosopher_must_eat)
				ph->should_die++;
			pthread_mutex_unlock(&ph->fork[ph->forkl]);
			pthread_mutex_unlock(&ph->fork[ph->forkr]);
		}
		printf("%lld %d is sleeping\n", curr_time(ph), ph->id);
		my_usleep(ph->time_to_sleep);
		if (ph->should_die == ph->number_of_times_each_philosopher_must_eat)
			exit(1);
	}
	return (0);
}

int	creat_threads(t_philos *phil, int ac, char **av)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	tasks(phil, ac, av);
	phil->fork = malloc(sizeof(pthread_mutex_t) * phil->number_of_philosophers);
	mutex(phil);
	while (i < phil->number_of_philosophers)
	{
		phil[i].fork = phil->fork;
		phil[i].id = i + 1;
		phil[i].forkl = i;
		phil[i].forkr = (i + 1) % phil->number_of_philosophers;
		phil[i].last_meal = get_time();
		phil->should_die = 0;
		phil[i].ate = 0;
		// phil[i].philo = malloc(sizeof(pthread_t));
		i++;
	}
	i = 0;
	while (i < phil->number_of_philosophers)
	{
		if (pthread_create(&phil[i].philo, NULL, &timing, &phil[i]) != 0)
			return (1);
			usleep (10);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < phil->number_of_philosophers)
		{
			// usleep (2e5);
			// printf ("%lld time passed for %d from the last meal is %lld\n", curr_time(phil), i+1, get_time() - phil[i].last_meal);
			if ((get_time() - phil[i].last_meal) >= phil->time_to_die)
			{
				printf("%lld %d died\n", curr_time(phil), phil[i].id);
				return (1);
			}
			i++;
		}
	}
	i = 0;
	while (i < phil->number_of_philosophers)
	{
		if (pthread_join(phil[i].philo, NULL) != 0)
			return (2);
		i++;
	}
	return (1);
}

void	check(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("./philo >>>>\033[31m number_of_philos"
			" && time_to_die && time_to_eat && time_to_sleep "
			"&& [number_of_times_eacih_philosopher_must_eat] \033[0m\n");
		exit(0);
	}
}

void	tasks(t_philos *ph, int ac, char **av)
{
	int	i;

	check(ac);
	i = -1;
	while (i++ < atoi(av[1]))
	{
		ph[i].number_of_philosophers = atoi(av[1]);
		ph[i].time_to_die = atoi(av[2]);
		ph[i].time_to_eat = atoi(av[3]);
		ph[i].time_to_sleep = atoi(av[4]);
		if (ac == 6)
			ph[i].number_of_times_each_philosopher_must_eat = atoi(av[5]);
	}
	if (ph->number_of_philosophers < 0)
		printf("Wrong number of philos\n");
	else if (ac == 6 && ph->number_of_times_each_philosopher_must_eat < 0)
		printf("Wrong number to eat\n");
	if (ph->time_to_die < 60)
		printf("Wrong time to die");
	else if (ph->time_to_eat < 60)
		printf("Wrong time to eat\n");
	else if (ph->time_to_sleep < 60)
		printf("Wrong time to sleep\n");
}
