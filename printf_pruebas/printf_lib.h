/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharo-c <maharo-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:06:23 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:12 by maharo-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBHH
# define PRINTF_LIB_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int ft_printf(char const *str, ...);
int	ft_putchar(int c);

#endif