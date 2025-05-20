#include "philo.h"

int	ft_f_ch(int id)
{
	return (id % 2 != 0);
}

int	ft_s_ch(int id)
{
	return (id % 2 != 0);
}

int	ft_life(t_ph *philo)
{
	pthread_t	*p;
	int			tmp;
	int			i;

	tmp = philo->previous->id;
	p = malloc(philo->previous->id * sizeof(pthread_t));
	if (!p)
		return (-1);
	i = 0;
	while (!(philo->info->death))
	{
		i = 0;
		while (i < tmp)
		{
			if (philo->id % 2 == 0)
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
	}
	free(p);
	return (0);
}
