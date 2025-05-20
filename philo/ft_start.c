#include "philo.h"

t_ph	*ft_creat_lst(t_philo data)
{
	int		i;
	t_ph	*philo;

	i = 0;
	philo = NULL;
	while (i < data.number_of_philo)
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

	philo = ft_creat_lst(data);
	if (!philo)
		return (-1);
	ft_life(philo);
	ft_lst_clear(&philo);
	return (0);
}
