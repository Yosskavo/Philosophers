/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:18:53 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/21 10:19:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_currenttime(t_ph *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	pthread_mutex_lock(&(philo->st));
	pthread_mutex_lock(&(philo->info->st));
	philo->start = ft_time(start) - philo->info->start;
	pthread_mutex_unlock(&(philo->st));
	pthread_mutex_unlock(&(philo->info->st));
	return (philo->start);
}

long long	ft_now_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (ft_time(start));
}
