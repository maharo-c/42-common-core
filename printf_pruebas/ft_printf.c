/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:17 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/20 19:45:11 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"
# include <stdarg.h>

static int	ft_checks(va_list va, char c)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(va, int));
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = write(1, &c, 1);
	return (count);
}

int ft_printf(char const *str, ...)
{
	int		len;
	va_list	va;

	len = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
			len += ft_checks(va, *(++str));
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(va);
	return (len);
}