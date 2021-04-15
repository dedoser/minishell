# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 01:35:10 by ehillman          #+#    #+#              #
#    Updated: 2021/04/15 18:57:26 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC =  	ft_isalnum.c\
		ft_itoa.c\
		ft_memmove.c\
		ft_putstr_fd.c\
		ft_strlcat.c\
		ft_strrchr.c\
		ft_toupper.c\
		ft_isalpha.c\
		ft_memccpy.c\
		ft_memset.c\
		ft_split.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_isascii.c\
		ft_memchr.c\
		ft_putchar_fd.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_bzero.c\
		ft_isdigit.c\
		ft_memcmp.c\
		ft_putendl_fd.c\
		ft_strdup.c\
		ft_strmapi.c\
		ft_substr.c\
		ft_calloc.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_putnbr_fd.c\
		ft_strjoin.c\
		ft_strncmp.c\
		ft_tolower.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strcmp.c\

OBJS = $(SRC:.c=.o)
LIB = ar rc

all:	$(NAME)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f libft.a

re:		fclean all

.PHONY:	all, clean, fclean, re, bonus
