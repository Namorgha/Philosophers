/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:09:52 by namorgha          #+#    #+#             */
/*   Updated: 2023/05/09 22:48:36 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	*ph;

	if (check(ac))
		return (1);
	ph = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	if (creat_threads(ph, ac, av) == 1)
	{
		free(ph->fork);
		return (1);
	}
	free(ph);
	return (0);
}
