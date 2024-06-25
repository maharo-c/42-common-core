# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margarita <margarita@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 15:45:17 by maharo-c          #+#    #+#              #
#    Updated: 2024/06/25 23:55:47 by margarita        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= \
				ft_printf.c\
				ft_printf_tools.c\
				ft_formats.c\
				ft_print_addr.c\
				ft_print_hex.c\

OBJS		= $(SRCS:.c=.o)
 
CC			= @cc
RM			= @rm -f
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)
			@echo "make all correct"

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 