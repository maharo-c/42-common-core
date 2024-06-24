/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:38 by margarita         #+#    #+#             */
/*   Updated: 2024/06/24 17:44:31 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putptr(void *ptr)
{
    int count;

    count = 0;
    count += ft_putstr("0x");
    count += ft_putnbr_base((unsigned long long)ptr, HEXL);
    return (count);
}
