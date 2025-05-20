#include "philo.h"

void	ft_p(char *mess, t_ph *philo)
{
	pthread_mutex_lock(&(philo->info->pm));
	printf("%s %d\n", mess, philo->id);
	pthread_mutex_unlock(&(philo->info->pm));
}

void	*ft_sleep(t_ph *philo)
{
	ft_p("is_sleeping", philo);
	usleep(philo->info->time_to_sleep);
	return (NULL);
}

void	*ft_think(void *data)
{
	t_ph	*philo;

	philo = (t_ph *)data;
	ft_p("is_thinking ", philo);
	usleep(philo->info->time_to_eat);
	return (NULL);
}

void	*ft_eat(void *data)
{
	t_ph *philo;

	philo = (t_ph *)(data);
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo->next->fork));
	ft_p("is_eating ", philo);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&(philo->next->fork));
	pthread_mutex_unlock(&(philo->fork));
	ft_sleep(philo);
	return (NULL);
}