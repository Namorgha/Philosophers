/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:09:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/03/30 03:47:57 by namorgha         ###   ########.fr       */
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
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				id;
	int				forkl;
	int				forkr;
	long long		last_meal;
	int				should_die;
	int				meals;
	pthread_t		philo;
	pthread_mutex_t	*fork;
	long long		start;
	struct s_philos	*info;
}				t_philos;

void			tasks(t_philos **ph, int ac, char **av);
void			check(int ac);
long long		curr_time(t_philos *philo);
void			death(t_philos *philo);
void			*timing(void *i);
int				creat_threads(t_philos *ph, int ac, char **av);
void			my_usleep(int ms);
long long int	get_time(void);
void			mutex(t_philos *ph);
void			philo_info(t_philos *phil, int i);

#endif
