/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:15:42 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/12 09:04:19 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_p(char *mess, t_ph *philo)
{
	pthread_mutex_lock(&(philo->info->pm));
	if (!(philo->info->death))
	{
		ft_currenttime(philo);
		printf("%llu %lld %s\n", philo->start, philo->id, mess);
	}
	pthread_mutex_unlock(&(philo->info->pm));
}

void	*ft_sleep(t_ph *philo)
{
	ft_p("is sleeping", philo);
	usleep(philo->info->time_to_sleep * 1000);
	return (NULL);
}

void	*ft_think(t_ph *philo)
{
	ft_p("is thinking", philo);
	usleep(philo->info->time_to_think * 1000);
	return (NULL);
}

// void ft_begning(t_ph *philo)
// {
// 	if (philo->id % 2 != 0)
// 	{
// 		ft_p("is thinking", philo);
// 		usleep(100);
// 	}
// }

void	*ft_routine(void *arg)
{
	t_ph	*philo;

	philo = (t_ph *)arg;
	pthread_mutex_lock(&(philo->te));
	philo->time_eat = 0;
	pthread_mutex_unlock(&(philo->te));
	ft_p("is thinking", philo);
	if (philo->id % 2)
		usleep(500);
	pthread_mutex_lock(&(philo->info->pm));
	while (!(philo->info->death))
	{
		pthread_mutex_unlock(&(philo->info->pm));
		if (ft_eat(philo))
			break ;
		ft_sleep(philo);
		ft_think(philo);
		pthread_mutex_lock(&(philo->info->pm));
	}
	pthread_mutex_unlock(&(philo->info->pm));
	return (NULL);
}
