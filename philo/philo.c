/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:22 by yel-mota          #+#    #+#             */
/*   Updated: 2025/05/07 15:12:49 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_puterror(char *str, int fd)
{
    write(fd, str, ft_strlen(str));
}

int ft_arguments_error(void)
{
    ft_puterror("you need at least 4 and most 5\n", 2);
    ft_puterror("number of philosophers\n", 2);
    ft_puterror("timr to die [in milliseconds]\n", 2);
    ft_puterror("time to eat [in milliseconds]\n", 2);
    ft_puterror("time to sleep [in milliseconds]\n", 2);
    ft_puterror("Number of time each phislosopher most eat (optinal)\n", 2);
    return (1);
}

int main(int ac, char **av)
{
    t_philo philo;

  if (!(ac == 5 || ac == 6))
    return (ft_arguments_error());
  if (!ft_parcing(av + 1, ac, &philo))
    return (ft_puterror("incorrect argument\n", 2), 1);
  ft_start(philo);
}
