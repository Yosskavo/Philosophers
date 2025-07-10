/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:15:32 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/22 09:49:55 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(struct timeval data)
{
	return ((long long)data.tv_sec * 1000 + data.tv_usec / 1000);
}

int	ft_life(t_ph *philo)
{
	pthread_t		*p;
	long long		id;
	long long		i;

	p = malloc((philo->previous->id + 1) * sizeof(pthread_t));
	id = philo->info->philos + 1;
	if (!p)
		return (-1);
	i = 0;
	philo->info->start = ft_now_time();
	pthread_create(&p[0], NULL, ft_monitoring, philo);
	i = 1;
	while (i < id)
	{
		pthread_create(&p[i], NULL, ft_routine, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < id)
	{
		pthread_join(p[i], NULL);
		i++;
	}
	return (free(p), 0);
}
