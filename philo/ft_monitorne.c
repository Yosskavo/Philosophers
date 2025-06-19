/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitorne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 04:52:36 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/19 06:43:10 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_monitorine(void *arg)
{
	t_ph *philo;
	int		tmp;

	philo = (t_ph *)arg;
	while (1) 
	{
		tmp = philo->start;
		tmp = ft_currenttime(philo) - tmp;
		if (tmp >= philo->info->time_to_die)
		{
			ft_p("deid", philo);
			tmp = philo->id;
			philo->info->death = 1;
			return (NULL);
		}
		philo = philo->next;
	}
	return (NULL);
}
