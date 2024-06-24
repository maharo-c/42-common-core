/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:17 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/24 22:43:49 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>

/**
 * 
 */

static int	ft_checks(va_list va, char c)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(va, int));
	if (c == 's')
		count = ft_putstr(va_arg(va, char *));
	/*else if (c == 'p')
		if (va_arg(va, void *) == NULL)
			count = ft_putstr("(nil)");
		else
			count = ft_putptr(va_arg(va, void *));*/
	if ((c == 'd') || (c == 'i') || (c == 'u'))
		count = ft_putnbr(va_arg(va, long), DEC);
	if (c == 'x')
		count = ft_putnbr_base((unsigned long)va_arg(va, long), HEXL);
	if (c == 'X')
		count = ft_putnbr_base((unsigned long)va_arg(va, long), HEXU);	
	if (c == '%')
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
