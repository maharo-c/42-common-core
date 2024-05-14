/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo <maharo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:39 by maharo            #+#    #+#             */
/*   Updated: 2024/05/14 13:29:07 by maharo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	if (dst_ptr <= src_ptr || src_ptr >= (dst_ptr + len))
	{
		while (len--)
		{
			*dst_ptr++ = *src_ptr++;
		}
	}
	else
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len--)
		{
			*dst_ptr-- = *src_ptr--;
		}
	}
	return (dst);
}
