/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:47:31 by margarita         #+#    #+#             */
/*   Updated: 2024/06/25 23:47:17 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned long long n, char *base)
{
	if (n < 16)
		ft_putchar(base[n]);
	else if (n > 15)
	{
		ft_put_hex(n / 16, base);
		ft_put_hex(n % 16, base);
	}
	else
		ft_putchar(n + 48);
}

int	ft_print_hex(unsigned long long n, char format)
{
	char	*base_x;
	char	*base_xx;
	int		len;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		if (format == 'x')
			ft_put_hex(n, base_x);
		if (format == 'X')
			ft_put_hex(n, base_xx);
	}
	while (n)
	{
		n /= 16;
		++len;
	}
	return (len);
}
