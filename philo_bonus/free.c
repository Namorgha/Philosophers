/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:25:29 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/25 09:20:53 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_all(t_philos *info)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < info->number_of_philosophers)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < info->number_of_philosophers)
				kill(info->child[i++], SIGINT);
			break ;
		}
	}
	sem_close(info->fork);
	free(info->child);
}
