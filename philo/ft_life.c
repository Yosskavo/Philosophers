#include "philo.h"

long long ft_time(struct timeval data)
{
	return ((long long)data.tv_sec * 1000 + data.tv_usec / 1000);
}

int	ft_life(t_ph *philo)
{
	pthread_t	*p;
	struct timeval start;
	int			id;
	int			i;

	p = malloc((philo->previous->id + 1) * sizeof(pthread_t));
	philo->info->philos = philo->previous->id;
	id = philo->previous->id + 1;
	if (!p)
		return (-1);
	i = 0;
	gettimeofday(&start, NULL);
	philo->info->start =  ft_time(start);
	pthread_create(&p[0], NULL, ft_monitorine, philo);
	i = 1;
	while (i < id)
	{
		pthread_create(&p[i], NULL, ft_routine, philo);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (!(philo->info->death))
		;
	while (i < id) 
	{
		pthread_join(p[i], NULL);
		i++;
	}
	free(p);
	return (0);
}
