/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 04:04:41 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/12 01:52:53 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_grab_fork(t_philos *philo)
{
	sem_wait(philo->fork);
	printf("%lld %d has taken a fork\n", curr_time(philo), philo->id);
}

void	routine(t_philos *philo)
{
	philo->start = get_time();
	pthread_create(&philo->philo, NULL, &check_time_of_death, philo);
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
