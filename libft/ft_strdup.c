/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:48:50 by maharo-c          #+#    #+#             */
/*   Updated: 2024/05/28 16:15:50 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (s == NULL) {
        return NULL;
    }
	size = ft_strlen(s) + 1;
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, size);
	return (dup);
}
 
/*int main (int argc, char **argv)
{
	(void)argc;
	char *res = strdup(argv[1]);
	printf("\n\t>>> USING strdup() <<<\n\n");
	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Returning res = \'%s\'\n", res);
	
	char *res2 = ft_strdup(argv[1]);
	printf("\n\t>>> USING ft_strdup() <<<\n\n");
	printf("Sending argv[1] = \'%s\'\n", argv[1]);
	printf("Returning res2 = \'%s\'\n", res2);
}*/