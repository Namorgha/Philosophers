/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:09:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/04/03 21:04:39 by namorgha         ###   ########.fr       */
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
	int				died;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				id;
	int				forkl;
	int				forkr;
	long long		last_meal;
	int				should_die;
	int				ate;
	int				*pointer;
	pthread_t		philo;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
	long long		start;
}				t_philos;

void			tasks(t_philos *ph, int ac, char **av);
int				check_time_of_death(t_philos *philo);
void			make_info(t_philos *philo);
void			check(int ac);
int				join(t_philos *philo);
void			check_error(t_philos *ph, int ac);
long long		curr_time(t_philos *philo);
void			*routine(void *i);
int				creat_threads(t_philos *ph, int ac, char **av);
int				ft_atoi(const char *str);
void			my_usleep(int ms);
long long int	get_time(void);
void			mutex(t_philos *ph);
void			taking_left_fork(t_philos *philo);
void			taking_right_fork(t_philos *philo);
void			is_eating(t_philos *philo);

#endif
