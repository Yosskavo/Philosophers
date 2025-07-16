/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 04:52:36 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/16 17:35:07 by yosskavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_eated(t_ph *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philos)
	{
		pthread_mutex_lock(&(philo->eats));
		if (philo->eat < philo->info->must_eat)
			return (pthread_mutex_unlock(&(philo->eats)), 0);
		pthread_mutex_unlock(&(philo->eats));
		philo = philo->next;
		i++;
	}
	return (1);
}

int	ft_first_test(t_ph *philo)
{
	if (ft_is_eated(philo))
	{
		pthread_mutex_lock(&(philo->info->pm));
		philo->info->death = 1;
		pthread_mutex_unlock(&(philo->info->pm));
		return (1);
	}
	return (0);
}

void	*ft_monitoring(void *arg)
{
	t_ph		*philo;
	long long	tmp;

	philo = (t_ph *)arg;
	tmp = 0;
	while (1)
	{
		pthread_mutex_lock(&(philo->te));
		pthread_mutex_lock(&(philo->info->st));
		tmp = ft_now_time() - philo->info->start - philo->time_eat;
		pthread_mutex_unlock(&(philo->te));
		pthread_mutex_unlock(&(philo->info->st));
		if (philo->info->must_eat > 0 && ft_first_test(philo))
			return (NULL);
		if (tmp > (long long)philo->info->time_to_die)
		{
			ft_p("died", philo);
			pthread_mutex_lock(&(philo->info->pm));
			philo->info->death = 1;
			return (pthread_mutex_unlock(&(philo->info->pm)), NULL);
		}
		philo = philo->next;
		usleep(5000);
	}
	return (NULL);
}
