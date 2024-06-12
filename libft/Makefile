# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maharo-c <maharo-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 12:51:15 by maharo            #+#    #+#              #
#    Updated: 2024/05/28 16:16:39 by maharo-c         ###   ########.fr        #
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
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		
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
