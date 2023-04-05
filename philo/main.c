/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:09:52 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/05 10:20:49 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	*ph;

	ph = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	if (creat_threads(ph, ac, av) == 1)
		return (1);
	return (0);
}
