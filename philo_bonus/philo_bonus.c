/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:49:47 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/07 09:44:43 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


void my_func(int i)
{
	// sem_t	sema;

	// sem_wait(&sema);
	printf("hellooooo process number >> ** [%d]\n", i);
	// sem_post(&sema);
}

int main(int ac, char **av) {
	int		num_processes;
	// sem_t	sema;
	pid_t	pid;
	int		i;

	i = 0;
	// sem_init(&sema, 1, 1);
	if (ac != 2)
	{
		printf("\033[0;30mError\033[0;30m\n");
		exit(1);
	}
	num_processes = atoi(av[1]);
	while (i < num_processes)
	{
		pid = fork();
		if (pid == 0)
		{
			my_func(i);
			exit(0);
		}
		i++;
	}
}
