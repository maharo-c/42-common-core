/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:05:13 by margarita         #+#    #+#             */
/*   Updated: 2024/06/28 18:25:29 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
	#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_text(int fd, char *text);
char	*get_line(char *text);
char	*clean_text(char *text);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_and_free(char *text, char *buffer);
char	*ft_strncpy(char *src, char *dest, size_t n_bytes);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);


#endif