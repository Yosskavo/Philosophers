/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:57:29 by yel-mota          #+#    #+#             */
/*   Updated: 2025/04/23 11:26:24 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_valid(char *str)
{
    int i;

    if (*str == '\0')
        return (0);
    i = -1;
    while (str[++i] == ' ')    
}

void ft_parcing(char **av)
{
    int i;
    
    i = 0;
    while (av[i])
    {
        if (!ft_valid(av[i++]))
            return (0);
    }
}