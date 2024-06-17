/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:23:55 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/13 11:53:32 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	minus;

	res = 0;
	minus = 1;
	while (*nptr != '\0' && ft_strchr("\t\n\v\f\r ", *nptr) != NULL)
		nptr++;
	if (*nptr != '\0' && ft_strchr("+-", *nptr) != NULL)
		if (*nptr++ == '-')
			minus *= -1;
	res = 0;
	while (*nptr != '\0' && ft_strchr("0123456789", *nptr) != NULL)
	{
		res *= 10;
		res += *nptr - '0';
		nptr++;
	}
	return (res * minus);
}
