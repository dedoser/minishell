# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 01:35:10 by ehillman          #+#    #+#              #
#    Updated: 2021/03/13 20:09:03 by fignigno         ###   ########.fr        #
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
		ft_strlcpy.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_isascii.c\
		ft_memchr.c\
		ft_putchar_fd.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_strtrim.c\
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
		ft_strcat\

BONUS =	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstadd_back.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
OBJS = $(SRC:.c=.o)
OBJS_B=$(BONUS:.c=.o)
LIB = ar rc

all:	$(NAME)

$(NAME): $(OBJS)
		$(LIB) $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(OBJS_B)

fclean:		clean
		rm -f libft.a

re:		fclean all

bonus:	$(OBJS) $(OBJS_B)
		$(LIB) $(NAME) $(OBJS) $(OBJS_B)

.PHONY:	all, clean, fclean, re, bonus
