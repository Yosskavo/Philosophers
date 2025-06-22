/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:15:12 by yel-mota          #+#    #+#             */
/*   Updated: 2025/06/21 10:30:06 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ph	*ft_lst_newphilo(int i, t_philo *data)
{
	t_ph	*philo;

	philo = malloc(sizeof(t_ph));
	if (!philo)
		return (NULL);
	philo->start = 0;
	philo->time_eat = 0;
	pthread_mutex_init(&(philo->fork), NULL);
	pthread_mutex_init(&(philo->st), NULL);
	pthread_mutex_init(&(philo->te), NULL);
	philo->info = data;
	pthread_mutex_init(&(philo->eats), NULL);
	philo->id = i + 1;
	philo->next = NULL;
	philo->previous = NULL;
	philo->eat = 0;
	return (philo);
}

int	ft_lst_add_philo(t_ph **list, t_ph *new)
{
	t_ph	*tmp;

	if (!new)
		return (-1);
	if (!*list)
		return (*list = new, 0);
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
	return (0);
}

void	ft_destroy(t_philo *data)
{
	pthread_mutex_destroy(&(data->pm));
	pthread_mutex_destroy(&(data->st));
	pthread_mutex_destroy(&(data->dt));
}

void	ft_lst_clear(t_ph **data)
{
	t_ph	*tmp;

	tmp = (*data)->previous;
	tmp->next = NULL;
	(*data)->previous = NULL;
	tmp = (*data)->next;
	ft_destroy((*data)->info);
	while (tmp)
	{
		pthread_mutex_destroy(&((*data)->fork));
		pthread_mutex_destroy(&((*data)->eats));
		pthread_mutex_destroy(&(*data)->st);
		pthread_mutex_destroy(&(*data)->te);
		(*data)->next = NULL;
		(*data)->previous = NULL;
		free(*data);
		*data = NULL;
		*data = tmp;
		tmp->previous = NULL;
		if (tmp)
			tmp = tmp->next;
	}
	pthread_mutex_destroy(&((*data)->fork));
	free(*data);
	data = NULL;
}

t_ph	*ft_lst_last_philo(t_ph *philo)
{
	while (philo->next)
	{
		philo = philo->next;
	}
	return (philo);
}
