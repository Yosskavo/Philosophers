#include "philo.h"

t_ph *ft_lst_newphilo(int i)
{
  t_ph *philo;

  philo = malloc(sizeof(t_ph *));
  if (!philo)
      return (NULL);
  philo->id = i + 1;
  philo->next = NULL;
  philo->previous = NULL;
  philo->froks = 0;
  return (philo);
}

void ft_lst_add_philo(t_ph **list, t_ph *new)
{
  t_ph *tmp;

  if (!*list)
  {
    *list = new;
    return ;
  }
  tmp = *list;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  new->previous = tmp;
}

void ft_lst_clear(t_ph **data)
{
    t_ph *tmp;

  tmp = (*data)->next;

  while (tmp)
  {
    printf ("%d\n" ,(*data)->id);
    free(*data);
    *data = NULL;
    *data = tmp;
    tmp->previous = NULL;
    if (tmp)
        tmp = tmp->next;
  }
}
