/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:09:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/03/24 17:32:50 by namorgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philos
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	pthread_mutex_t		*fork;
	int					i;

}				t_philos;

typedef struct s_info
{
	t_philos	philos;
	int			finish;
}		t_info;

void	tasks(t_philos *ph, int ac, char **av);
void	check(int ac, char **av);
void	*run(void);
int		creat_threads(t_philos *ph, int ac, char **av);
void	get_curr_time(void);

#endif
