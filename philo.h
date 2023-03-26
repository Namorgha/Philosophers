/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namorgha <namorgha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:09:46 by namorgha          #+#    #+#             */
/*   Updated: 2023/03/26 01:26:17 by namorgha         ###   ########.fr       */
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
	int				id;
	int				forkl;
	int				forkr;
	long long		last_meal;
	int				meals;
	pthread_t		*philo;
	struct s_info	*info;
}				t_philos;

typedef struct s_info
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	long long			start_time;
	pthread_mutex_t		*fork;
	t_philos			*philos;
}				t_info;

void			tasks(t_info *ph, int ac, char **av);
void			check(int ac);
void			*run(void *i);
void			*timing(void *i);
int				creat_threads(t_info *ph, int ac, char **av);
void			get_curr_time(void);
long long int	curr_time(void);
long long int	get_time(void);

#endif
