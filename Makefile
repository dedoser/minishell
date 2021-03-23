# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 22:44:15 by ngonzo            #+#    #+#              #
#    Updated: 2021/03/23 19:45:52 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -g
SRCS =	gnl/get_next_line.c gnl/get_next_line_utils.c parser_read_line/read_line.c\
		main.c ft_start.c parser_read_line/ft_utils.c parser_read_line/hist.c parser_read_line/parser.c \
		parser_read_line/found_args_div.c parser_read_line/divide_coms.c parser_read_line/special_char_parser.c \
		parser_read_line/paste_envp.c parser_read_line/delete_protecting.c parser_read_line/create_final_mass.c \

OBJS = $(SRCS:c=o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	gcc -ltermcap $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJS): %.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TERM_OBJS)
	$(MAKE) fclean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
