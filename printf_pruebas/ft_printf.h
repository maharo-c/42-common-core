/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margarita <margarita@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:06:23 by maharo-c          #+#    #+#             */
/*   Updated: 2024/06/21 10:54:44 by margarita        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>

# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
# define DEC "0123456789"

int ft_printf(char const *str, ...);
int	ft_putchar(int c);
int ft_putstr(char *str);
int ft_putptr(void *ptr);
int	ft_putnbr_base(unsigned long nbr, char *base);
int ft_putnbr(long nbr, char *base);

#endif