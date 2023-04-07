/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:09:52 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/07 06:18:33 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	*ph;

	check(ac);
	ph = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	if (creat_threads(ph, ac, av) == 1)
	{
		free(ph);
		return (1);
	}
	free(ph);
	return (0);
}
