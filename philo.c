/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:22 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/23 10:57:23 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_puterror(void)
{
    printf("you need at least 4 and most 5\n");
    printf("number of philosophers\n");
    printf("timr to die [in milliseconds]\n");
    printf("time to eat [in milliseconds]\n");
    printf("time to sleep [in milliseconds]\n");
    printf("Number of time each phislosopher most eat (optinal)\n");
    return (1);
}

int main(int ac, char **av)
{
    if (!(ac == 5 || ac == 6))
        return (ft_puterror());
    ft_parcing(av + 1);
}
