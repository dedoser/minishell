# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 22:44:15 by ngonzo            #+#    #+#              #
#    Updated: 2021/03/16 23:20:49 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -g
SRCS =	gnl/get_next_line.c gnl/get_next_line_utils.c \
		ft_start.c ft_utils.c hist.c main.c parser.c \
		found_args_div.c divide_coms.c special_char_parser.c 
OBJS = $(SRCS:c=o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) fclean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
