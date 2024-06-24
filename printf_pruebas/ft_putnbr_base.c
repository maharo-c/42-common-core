/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:47:31 by margarita         #+#    #+#             */
/*   Updated: 2024/06/24 17:42:25 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	size_t  base_len;
    int     len;

    base_len = 0;
    while (base[base_len] != '\0')
        base_len++;
    len = 0;
    if (nbr >= base_len)
	    len +=  ft_putnbr_base(nbr / base_len, base);
	len += ft_putchar(base[nbr % base_len]);
    return (len);
}
