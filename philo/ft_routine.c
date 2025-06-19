#include "philo.h"

long long	ft_currenttime(t_ph *philo)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	philo->start = ft_time(start) - philo->info->start;
	return (philo->start);
}

long long	ft_now_time(void)
{
	struct timeval start;

	gettimeofday(&start, NULL);
	return (ft_time(start));
}

void	ft_p(char *mess, t_ph *philo)
{
	pthread_mutex_lock(&(philo->info->pm));
	if (!(philo->info->death))
	{
		ft_currenttime(philo);
		printf("%llu %d %s\n", philo->start, philo->id, mess);
	}
	pthread_mutex_unlock(&(philo->info->pm));
}

void	*ft_sleep(t_ph *philo)
{
	ft_p("is sleeping", philo);
	usleep(philo->info->time_to_sleep * 1000);
	philo->eat = 0;
	return (NULL);
}

void	*ft_think(t_ph *philo)
{
	ft_p("is thinking", philo);
	if (philo->info->philos % 2 != 0 && philo->info->time_to_eat > philo->info->time_to_sleep - 5)
		usleep((philo->info->time_to_eat - philo->info->time_to_sleep + 5) * 1000);
return (NULL);
}

void	*ft_eat(t_ph *philo)
{
    if (philo->id % 2 == 0)
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
	philo->time_eat = ft_currenttime(philo);
	usleep(philo->info->time_to_eat *  1000);
	philo->eat += 1;
    if (philo->id % 2 == 0)
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

void *ft_routine(void *arg)
{
	t_ph *philo;
	int		i;

	philo = (t_ph *)arg;
	if (philo->info->philos % 2 == 0)
		i = 0;
	else
		i = 1;
	philo = (t_ph *)(arg);
	if (philo->id % 2 == 0)
		usleep(100);
	while (!(philo->info->death))
	{
		ft_think(philo);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}
