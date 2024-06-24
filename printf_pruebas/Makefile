# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margarita <margarita@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 15:45:17 by maharo-c          #+#    #+#              #
#    Updated: 2024/06/24 08:26:24 by margarita        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	ft_printf.c	ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr_base.c ft_putnbr.c
OBJS			= $(SRCS:.c=.o)
 
CC				= @cc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)
				@echo "make all correct"

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 