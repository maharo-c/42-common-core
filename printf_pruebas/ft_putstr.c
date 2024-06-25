/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:53:59 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/25 13:22:53 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *str)
{
    int count;

    count = 0;
    if (!str)
        str = "(null)";
    while (*str)
        count += write(1, str++, 1);
    
    return (count);
}
