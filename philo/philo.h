/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:26 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/16 21:02:36 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		time_to_think;
	int				death;
	pthread_mutex_t	pm;
	pthread_mutex_t	st;
	pthread_mutex_t	dt;
	long long		must_eat;
	long long		start;
	long long		philos;
}					t_philo;

/*
  next is the left
  previous is the right
*/

typedef struct s_ph
{
	pthread_mutex_t	fork;
	pthread_mutex_t	eats;
	pthread_mutex_t	st;
	pthread_mutex_t	te;
	long long		eat;
	long long		id;
	long long		time_eat;
	long long		start;
	long long		old;
	t_philo			*info;
	struct s_ph		*next;
	struct s_ph		*previous;
}					t_ph;

int					ft_parcing(char **av, int ac, t_philo *data);
int					ft_start(t_philo data);
t_ph				*ft_lst_newphilo(int id, t_philo *data);
int					ft_lst_add_philo(t_ph **list, t_ph *new);
void				ft_lst_clear(t_ph **data);
t_ph				*ft_lst_last_philo(t_ph *philo);
int					ft_life(t_ph *philo);
size_t				ft_strlen(char *str);

// time

long long			ft_time(struct timeval data);
long long			ft_currenttime(t_ph *philo);
long long			ft_now_time(void);
void				ft_usleep(t_ph *philo, int time);
/// functions for routine of philosophers

void				*ft_routine(void *arg);
void				ft_p(char *mess, t_ph *philo);
void				*ft_monitoring(void *arg);

// routines

int					ft_eat(t_ph *philo);

#endif
