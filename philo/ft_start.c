#include "philo.h"

void ft_start(t_philo data)
{
  int i;
  t_ph *philo;
  t_ph *tmp;

  i = 0;
  philo = NULL;
  while (i < data.number_of_philo)
  {
    ft_lst_add_philo(&philo, ft_lst_newphilo(i));
    i++;
  }
  printf("%d\n", i);
  tmp = philo;
  while (tmp)
  {
    printf("%d\n", tmp->id);
    tmp = tmp->next;
  }
  ft_lst_clear(&philo);
}
