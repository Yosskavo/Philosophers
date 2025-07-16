/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:17:47 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/16 13:45:03 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_one(t_ph *philo)
{
	pthread_mutex_lock(&(philo->fork));
	ft_p("has taken a fork", philo);
	while (philo->info->philos == 1)
	{
		pthread_mutex_lock(&(philo->info->pm));
		if (philo->info->death == 1)
		{
			pthread_mutex_unlock(&(philo->info->pm));
			pthread_mutex_unlock(&(philo->fork));
			return (1);
		}
		pthread_mutex_unlock(&(philo->info->pm));
		usleep(100);
	}
	return (1);
}

void	ft_he_ate(t_ph *philo)
{
	pthread_mutex_lock(&(philo->eats));
	philo->eat += 1;
	pthread_mutex_unlock(&(philo->eats));
}

int	ft_eat(t_ph *philo)
{
	if (philo->info->philos == 1)
		return (ft_one(philo));
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->fork));
		ft_p("has taken a fork", philo);
		pthread_mutex_lock(&(philo->next->fork));
		ft_p("has taken a fork", philo);
	}
	else
	{
		pthread_mutex_lock(&(philo->next->fork));
		ft_p("has taken a fork", philo);
		pthread_mutex_lock(&(philo->fork));
		ft_p("has taken a fork", philo);
	}
	pthread_mutex_lock(&(philo->te));
	philo->time_eat = ft_currenttime(philo);
	pthread_mutex_unlock(&(philo->te));
	ft_p("is eating", philo);
	ft_he_ate(philo);
	ft_usleep(philo, philo->info->time_to_eat * 1000);
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
	return (0);
}
