/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:53:38 by margarita         #+#    #+#             */
/*   Updated: 2024/06/26 00:22:06 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_putstr("(nil)");
	else
	{
		len += write(1, "0x", 2);
		len += ft_print_hex(n, 'x');
	}
	return (len);
}
