#include "philo.h"

long long ft_time(struct timeval data)
{
	return ((long long)data.tv_sec * 1000 + data.tv_usec / 1000);
}

int	ft_life(t_ph *philo)
{
	pthread_t	*p;
	struct timeval start;
	int			tmp;
	int			i;
    int j;

	tmp = philo->previous->id;
	p = malloc(philo->previous->id * sizeof(pthread_t));
	if (!p)
		return (-1);
	i = 0;
    j = 0;
	gettimeofday(&start, NULL);
	philo->info->start =  ft_time(start);
	while (!(philo->info->death))
	{
		i = 0;
		while (i < tmp)
		{
			if (philo->eat == 1)
				pthread_create(&p[i], NULL, ft_sleep, philo);
			else if ((philo->id + j) % 2 != 0)
                pthread_create(&p[i], NULL, ft_eat, philo);
			else
				pthread_create(&p[i], NULL, ft_think, philo);
			philo = philo->next;
			i++;
		}
		i = 0;
		while (i < tmp) 
		{
			pthread_join(p[i], NULL);
			i++;
			philo = philo->next;
		}
        if (!j)
            j++;
        else
            j--;
	}
	free(p);
	return (0);
}
