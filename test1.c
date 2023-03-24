/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/03/24 18:22:47 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mut(t_philos *ph, int ac, char **av)
{
	int				i;

	i = 0;
	while (i < ph->number_of_philosophers)
	{
		pthread_mutex_init(&ph->fork[i], NULL);
		i++;
	}
}

void	*timing(void *i)
{
	t_philos		*ph;
	int				y;

	ph = i;
	y = ph->i;
	while (1)
	{
		pthread_mutex_lock(&ph->fork[y]);
		printf("%d has taken a fork\n", y);
		pthread_mutex_lock(&ph->fork[(y + 1) % ph->number_of_philosophers]);
		printf("%d has taken a fork\n", y);
		printf("%d is eating\n", y);
		usleep(ph->time_to_eat * 1000);
		printf("%d is sleeping\n", y);
		pthread_mutex_unlock(&ph->fork[y]);
		pthread_mutex_unlock(&ph->fork[(y + 1) % ph->number_of_philosophers]);
		usleep(ph->time_to_sleep * 1000);
		printf("%d is thinking\n", y);
	}
	return (0);
}

int	creat_threads(t_philos *ph, int ac, char **av)
{
	pthread_t		*th;
	int				*j;

	ph->i = 0;
	ph = malloc(sizeof(t_philos));
	th = malloc(sizeof(pthread_t) * ph->number_of_philosophers);
	ph->fork = malloc(sizeof(pthread_mutex_t) * ph->number_of_philosophers);
	tasks(ph, ac, av);
	mut(ph, ac, av);
	while (ph->i < ph->number_of_philosophers)
	{
		if (pthread_create(&th[ph->i], NULL, &timing, ph) != 0)
			return (1);
		usleep (1000);
		ph->i++;
	}
	ph->i = 0;
	while (ph->i < ph->number_of_philosophers)
	{
		if (pthread_join(th[ph->i], NULL) != 0)
			return (2);
		ph->i++;
	}
	return (1);
}

void	get_curr_time(void)
{
	struct timeval	start;
	struct timeval	end;
	long int		elapsed_time;

	gettimeofday(&start, NULL);
	// timing();
	gettimeofday(&end, NULL);
	elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + \
		(end.tv_usec - start.tv_usec);
	printf("%ld is eating\n", elapsed_time / 1000);
}

void	check(int ac, char **av)
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
	check(ac, av);
	ph->number_of_philosophers = atoi(av[1]);
	ph->time_to_die = atoi(av[2]);
	ph->time_to_eat = atoi(av[3]);
	ph->time_to_sleep = atoi(av[4]);
	if (ac == 6)
	{
		ph->number_of_philosophers = atoi(av[5]);
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
