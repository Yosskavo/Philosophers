#include "philo.h"

void	ft_currenttime(t_ph *philo)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	philo->start = ft_time(start) - philo->info->start;
}

void	ft_p(char *mess, t_ph *philo)
{
	pthread_mutex_lock(&(philo->info->pm));
	ft_currenttime(philo);
	printf("%llu %d %s\n", philo->start, philo->id, mess);
	pthread_mutex_unlock(&(philo->info->pm));
}

void	*ft_sleep(void *data)
{
	t_ph *philo;

	philo = (t_ph *)(data);
	
	ft_p("is sleeping", philo);
	usleep(philo->info->time_to_sleep * 1000);
	philo->eat = 0;
	return (NULL);
}

void	*ft_think(void *data)
{
	t_ph	*philo;

	philo = (t_ph *)data;
	ft_p("is thinking", philo);
	usleep(philo->info->time_to_eat * 1000);
	return (NULL);
}

void	*ft_eat(void *data)
{
	t_ph *philo;

	philo = (t_ph *)(data);
    if (&(philo->fork) > &(philo->next->fork))
    {
	    pthread_mutex_lock(&(philo->fork));
		ft_p("has taken a fork", philo);
	    pthread_mutex_lock(&(philo->next->fork));
		ft_p("has taken a fork", philo);
    }
    else
    {
	    pthread_mutex_lock(&(philo->next->fork));
		ft_p("has taken a fork", philo);
		pthread_mutex_lock(&(philo->fork));
		ft_p("has taken a fork", philo);
	}
	ft_p("is eating", philo);
	philo->eat = 1;
	usleep(philo->info->time_to_eat * 1000);
    if (&(philo->fork) > &(philo->next->fork))
    {
	    pthread_mutex_unlock(&(philo->fork));
	    pthread_mutex_unlock(&(philo->next->fork));
    }
    else
    {
	    pthread_mutex_unlock(&(philo->next->fork));
		pthread_mutex_unlock(&(philo->fork));
	}
	return (NULL);
}
