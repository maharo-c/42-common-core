# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maharo <maharo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 12:51:15 by maharo            #+#    #+#              #
#    Updated: 2024/05/14 14:25:19 by maharo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "make all correct"

$(OBJS): %.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@echo "make clean correct"

fclean: clean
	@rm -f $(NAME)
	@echo "make fclean correct"

re: fclean all
	@echo "make re correct"

.PHONY: all clean fclean re bonu
