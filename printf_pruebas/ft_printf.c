/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:17 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:08 by maharo-c         ###   ########.fr       */
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
		count = write
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
			;
	}
}