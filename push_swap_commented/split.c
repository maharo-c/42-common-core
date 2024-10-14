/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:55:42 by margarita         #+#    #+#             */
/*   Updated: 2024/09/24 08:04:06 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	nw = 0;
	int	i = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
		{
                        nw++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}		
	}
	return nw;
}

char	*ft_strncpy(char *dst, char *src, int size)
{
	int	i = 0;
	
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

char    **ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	unsigned int	num_words;
	char	**result;

	num_words = count_words(str);
	result = (char **)malloc(sizeof(char *) * (num_words + 1));

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		result[k] = (char *)malloc(sizeof(char) * (i - j + 1));
		ft_strncpy(result[k], &str[j], i - j);
		k++;
	}
	result[k] = NULL;
	return (result);
}