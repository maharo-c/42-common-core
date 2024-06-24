/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:44:02 by margarita         #+#    #+#             */
/*   Updated: 2024/06/24 17:42:33 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putnbr(long nbr, char *base)
{
    int count;

    count = 0;
    if (nbr < 0)
    {
        count += ft_putchar('-');
        nbr = -nbr;
    }
    count += ft_putnbr_base((unsigned long)nbr, base);
    return (count);
}
