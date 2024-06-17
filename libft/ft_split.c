/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 06:20:25 by margarita         #+#    #+#             */
/*   Updated: 2024/06/16 20:59:34 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cwords;
	int	in_word;

	in_word = 0;
	cwords = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			cwords++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (cwords);
}

static void	*ft_free(char **memry, size_t aux)
{
	size_t	i;

	i = 0;
	while (i < aux)
	{
		free(memry[i]);
		i++;
	}
	free(memry);
	return (NULL);
}

static int	split_str(char **ptr, char *str, char c, int nwords)
{
	int		i;
	char	*start;

	i = 0;
	start = str;
	while (i < nwords)
	{
		while (*str && *str != c)
			str++;
		ptr[i] = ft_substr(start, 0, str - start);
		if (!ptr[i])
		{
			ft_free(ptr, i);
			return (1);
		}
		i++;
		while (*str == c)
			str++;
		start = str;
	}
	ptr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		nwords;
	char	**ptr;
	char	*str;
	char	delim[2];

	delim[0] = c;
	delim[1] = '\0';
	if (!s)
		return (NULL);
	str = ft_strtrim(s, delim);
	if (!str)
		return (NULL);
	nwords = count_words(str, c);
	ptr = ft_calloc((nwords + 1), sizeof(char *));
	if (!ptr)
		return (free(str), NULL);
	if (split_str(ptr, str, c, nwords))
		return (free(str), NULL);
	return (free(str), ptr);
}
