/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:26 by yel-mota          #+#    #+#             */
/*   Updated: 2025/05/22 14:22:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int death;
    pthread_mutex_t pm;
    pthread_mutex_t st;
    int time_to_sleep;
    int must_eat;
    long long start;
}   t_philo;

/*
  next is the left 
  previous is the right
*/

typedef struct s_ph
{
    pthread_mutex_t fork;
    int             eat;
    int              id;
    long long         start;
    t_philo          *info;
    struct s_ph     *next;
    struct s_ph     *previous;
}   t_ph;

int ft_parcing(char **av, int ac, t_philo *data);
int ft_start(t_philo data);
t_ph *ft_lst_newphilo(int id, t_philo * data);
int ft_lst_add_philo(t_ph **list, t_ph *new);
void ft_lst_clear(t_ph **data);
t_ph *ft_lst_last_philo(t_ph *philo);
int ft_life(t_ph *philo);
long long ft_time(struct timeval data);



/// functions for routine of philosophers

void  *ft_sleep(void *philo);
void  *ft_think(void *data);
void  *ft_eat(void *data);
void  ft_p(char *mess, t_ph *philo);

#endif
