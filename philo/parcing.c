/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/22 11:14:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *num)
{
	long long	res;
	int			i;

	i = 0;
	while (num[i] == ' ' || (num[i] >= 9 && num[i] <= 13))
		i++;
	if (num[i] == '+')
		i++;
	res = 0;
	while (num[i])
	{
		res = res * 10 + num[i] - '0';
		i++;
	}
	return (res);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_valid(char *str)
{
	int	i;

	if (*str == '\0')
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '\0' || str[i] == '+')
		return (0);
	while (str[i] == '0')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_full(char **av, t_philo *data)
{
	data->philos = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
}

int	ft_parcing(char **av, int ac, t_philo *data)
{
	int	i;

	i = 0;
	memset(data, 0, sizeof(t_philo));
	while (av[i])
	{
		if (!ft_valid(av[i]))
			return (0);
		i++;
	}
	ft_full(av, data);
	if (data->philos <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (0);
	if (ac == 6)
	{
		data->must_eat = ft_atoi(av[4]);
		if (data->must_eat <= 0)
			return (0);
	}
	else
		data->must_eat = -1;
	return (1);
}
