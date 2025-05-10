/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:26 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/24 07:57:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
}   t_philo;

/*
  next is the left 
  previous is the right
*/

typedef struct s_ph
{
    pthread_mutex_t fork;
    int             froks;
    int id;
    struct s_ph     *next;
    struct s_ph     *previous;
}   t_ph;

int ft_parcing(char **av, int ac, t_philo *data);
void ft_start(t_philo data);
t_ph *ft_lst_newphilo(int id);
void ft_lst_add_philo(t_ph **list, t_ph *new);
void ft_lst_clear(t_ph **data);

#endif
