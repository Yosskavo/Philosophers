/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitorne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 04:52:36 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/19 23:22:32 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_is_eated(t_ph *philo)
{
	int i;

	i = 0;
	while (i < philo->info->philos)
	{
		if (philo->eat < philo->info->must_eat)
			return (0);
		philo = philo->next;
		i++;
	}
	return (1);
}

void *ft_monitorine(void *arg)
{
	t_ph *philo;
	long long		tmp;

	philo = (t_ph *)arg;
	// printf ("%llu %llu %d\n", philo->time_eat, philo->info->start, philo->info->time_to_die);
	while (1) 
	{
		// tmp = philo->info->start;
		tmp = ft_now_time() - philo->info->start - philo->time_eat;
		if (ft_is_eated(philo))
		{
			philo->info->death = 1;
			return (NULL);
		}
		if (tmp > philo->info->time_to_die)
		{
			// printf ("%lld %llu\n", tmp, philo->start);
			ft_p("died", philo);
			tmp = philo->id;
			philo->info->death = 1;
			return (NULL);
		}
		philo = philo->next;
		usleep(1000);
	}
	return (NULL);
}
