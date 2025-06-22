/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:15:22 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/22 09:30:32 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ph	*ft_creat_lst(t_philo data)
{
	int		i;
	t_ph	*philo;

	i = 0;
	philo = NULL;
	pthread_mutex_init(&(data.pm), NULL);
	pthread_mutex_init(&(data.st), NULL);
	pthread_mutex_init(&(data.dt), NULL);
	while (i < data.philos)
	{
		if (ft_lst_add_philo(&philo, ft_lst_newphilo(i, &data)) == -1)
			return (ft_lst_clear(&philo), NULL);
		i++;
	}
	philo->previous = ft_lst_last_philo(philo);
	philo->previous->next = philo;
	return (philo);
}

int	ft_start(t_philo data)
{
	t_ph	*philo;

	if (data.philos % 2 != 0
		&& data.time_to_eat >= data.time_to_sleep - 5)
		data.time_to_think = (data.time_to_eat - data.time_to_sleep + 5);
	philo = ft_creat_lst(data);
	if (!philo)
		return (-1);
	ft_life(philo);
	ft_lst_clear(&philo);
	return (0);
}
