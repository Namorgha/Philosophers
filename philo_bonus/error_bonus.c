/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:20:07 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/11 23:08:13 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_error(t_philos *ph, int ac)
{
	if (ph->time_to_die < 60)
	{
		printf("\033[31mWrong time to die\033[31m\n");
		exit (1);
	}
	else if (ph->time_to_eat < 60)
	{
		printf("\033[31mWrong time to eat\033[31m\n");
		exit (1);
	}
	else if (ph->time_to_sleep < 60)
	{
		printf("\033[31mWrong time to sleep\033[31m\n");
		exit (1);
	}
	else if (ac == 6 && ph->number_of_times_each_philosopher_must_eat <= 0)
	{
		printf("\033[31mWrong number to eat\033[31m\n");
		exit (1);
	}
}

void	tasks(t_philos *ph, int ac, char **av)
{
	int	i;
	int	n;

	n = ft_atoi(av[1]);
	if (n < 1)
	{
		printf("\033[31mError: number of "\
			"philosophers must be positive.\033[31m\n");
		exit(1);
	}
	check(ac);
	i = -1;
	while (i++ < n)
	{
		ph[i].number_of_philosophers = n;
		ph[i].time_to_die = ft_atoi(av[2]);
		ph[i].time_to_eat = ft_atoi(av[3]);
		ph[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			ph[i].number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	}
	check_error(ph, ac);
}

void	check(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("\033[0;30m./philo\033[0;30m \033[31m [number_of_philos]"
			"  [time_to_die]  [time_to_eat]  [time_to_sleep]"
			"  [number_of_times_eacih_philosopher_must_eat] \033[0m\n");
		exit(0);
	}
}

void	check_d(t_philos *philo)
{
	if (philo->ate == philo->number_of_times_each_philosopher_must_eat)
	{
		philo->num_ate = 1;
	}
}
