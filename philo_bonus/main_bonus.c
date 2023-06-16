/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 05:09:52 by namorgha          #+#    #+#             */
/*   Updated: 2023/06/16 08:38:37 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philos	*ph;

	check(ac);
	ph = malloc(sizeof(t_philos) * ft_atoi(av[1]));
	creat_threads(ph, ac, av);
	ft_free_all(ph);
	return (0);
}
