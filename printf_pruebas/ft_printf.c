/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:28:02 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/25 16:30:16 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdarg.h>

/**
 * 
 */

static int	ft_checks(va_list va, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(va, int));
	if (c == 's')
		count += ft_putstr(va_arg(va, char *));
	/*if (c == 'p')
	{
		if (va_arg(va, void *) == NULL)
			count = ft_putstr("(nil)");
		else
			count = ft_putptr(va_arg(va, void *));
	}
	if ((c == 'd') || (c == 'i') || (c == 'u'))
		count = ft_putnbr(va_arg(va, long), DEC);
	if (c == 'x')
		count = ft_putnbr_base((unsigned long)va_arg(va, long), HEXL);
	if (c == 'X')
		count = ft_putnbr_base((unsigned long)va_arg(va, long), HEXU);*/
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	va;

	i = 0;
	len = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_checks(va, str[i+1]);
			i++;
		}
		else
			len += ft_putchar(*str);
		i++;
	}
	va_end(va);
	return (len);
}
