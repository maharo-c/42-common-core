/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:38 by margarita         #+#    #+#             */
/*   Updated: 2024/06/25 12:37:17 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_putptr(void *ptr)
{
    int count;

    if (ptr == NULL)
        return (ft_putstr("(nil)"));
        
    count = 0;
    count += ft_putstr("0x");
    count += ft_putnbr_base((unsigned long long)ptr, HEXL);
    return (count);
}
