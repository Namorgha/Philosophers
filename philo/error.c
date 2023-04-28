/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:20:07 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/28 12:14:28 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(t_philos *ph, int ac, char **av)
{
	int	n;

	n = ft_atoi(av[1]);
	if (n < 1)
	{
		return (printf("\033[31mError: number of "\
			"philosophers must be positive.\033[31m\n"));
	}
	else if (ph->time_to_die < 60)
		return (printf("\033[31mWrong time to die\033[31m\n"));
	else if (ph->time_to_eat < 60)
		return (printf("\033[31mWrong time to eat\033[31m\n"));
	else if (ph->time_to_sleep < 60)
		return (printf("\033[31mWrong time to sleep\033[31m\n"));
	else if (ac == 6 && ph->number_of_times_each_philosopher_must_eat <= 0)
		return (printf("\033[31mWrong number to eat\033[31m\n"));
	return (0);
}

void	tasks(t_philos *ph, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		ph[i].number_of_philosophers = ft_atoi(av[1]);
		ph[i].time_to_die = ft_atoi(av[2]);
		ph[i].time_to_eat = ft_atoi(av[3]);
		ph[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			ph[i].number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	}
}

int	check(int ac)
{
	if (ac != 5 && ac != 6)
	{
		return (printf("\033[0;30m./philo\033[0;30m \033[31m [number_of_philos]"
				"  [time_to_die]  [time_to_eat]  [time_to_sleep]"
				"  [number_of_times_eacih_philosopher_must_eat] \033[0m\n"));
	}
	return (0);
}

int	check_d(t_philos *philo)
{
	if (philo->ate == philo->number_of_times_each_philosopher_must_eat)
	{
		philo->num_ate = 1;
		return (1);
	}
	return (0);
}
