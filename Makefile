# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 22:44:15 by ngonzo            #+#    #+#              #
#    Updated: 2021/04/03 16:11:33 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -g -Wall -Werror -Wextra
SRCS =	gnl/get_next_line.c gnl/get_next_line_utils.c parser_read_line/read_line.c\
		main.c ft_start.c parser_read_line/ft_utils.c parser_read_line/hist.c parser_read_line/parser.c \
		parser_read_line/found_args_div.c parser_read_line/divide_coms.c parser_read_line/special_char_parser.c \
		parser_read_line/paste_envp.c parser_read_line/delete_protecting.c parser_read_line/create_final_mass.c \
		parser_read_line/check_args.c create_com.c run_com.c launch_com.c find_com.c build_in.c exit_com.c \
		export_build_in.c export_out.c unset_com.c delete_all.c
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
