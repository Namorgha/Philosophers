/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/28 11:46:05 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philos *philo)
{
	pthread_create(&philo->philo, NULL, &check_time_of_death, philo);
	while (!(*philo->pointer))
	{
		if (!(*philo->pointer))
		{
			sem_wait(philo->print);
			printf("%lld %d is thinking\n", curr_time(philo), philo->id);
			sem_post(philo->print);
		}
		taking_fork(philo);
		is_eating(philo);
		if (!(*philo->pointer))
		{
			sem_wait(philo->print);
			printf("%lld %d is sleeping\n", curr_time(philo), philo->id);
			sem_post(philo->print);
		}
		my_usleep(philo->time_to_sleep);
	}
}

void	creat_threads(t_philos *phil, int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	tasks(phil, ac, av);
	make_info(phil);
	init_sem(phil);
	phil->child = malloc(sizeof(int) * phil->number_of_philosophers);
	phil->start = get_time();
	while (i < phil->number_of_philosophers)
		phil[i++].start = phil->start;
	i = 0;
	while (i < phil->number_of_philosophers)
	{
		pid = fork();
		if (pid == 0)
			routine(&phil[i]);
		else
			phil->child[i] = pid;
		i++;
	}
}
