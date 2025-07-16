/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:26:55 by yel-mota          #+#    #+#             */
/*   Updated: 2025/07/16 13:40:50 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(t_ph *philo, int time)
{
	while (time)
	{
		pthread_mutex_lock(&(philo->info->pm));
		if (philo->info->death == 1)
		{
			pthread_mutex_unlock(&(philo->info->pm));
			return ;
		}
		pthread_mutex_unlock(&(philo->info->pm));
		if (time > 10000)
		{
			usleep(10000);
			time -= 10000;
		}
		else
		{
			usleep(time);
			time = 0;
		}
	}
}
