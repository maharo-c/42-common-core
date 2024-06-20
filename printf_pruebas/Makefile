# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: margarita <margarita@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 15:45:17 by maharo-c          #+#    #+#              #
#    Updated: 2024/06/20 19:44:17 by margarita        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_print.c ft_putchar.c
OBJS			= $(SRCS:.c=.o)
 
CC				= @cc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= printf_lib.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re 