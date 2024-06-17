/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:32:08 by margarita         #+#    #+#             */
/*   Updated: 2024/06/15 08:17:18 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h> // Necesario para toupper

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
