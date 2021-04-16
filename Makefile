# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 22:44:15 by ngonzo            #+#    #+#              #
#    Updated: 2021/04/16 22:26:09 by fignigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -g -Wall -Werror -Wextra
SRCS =	read_line/read_line.c read_line/press_key.c\
		\
		parser/ft_utils.c parser/hist.c parser/parser.c \
		parser/found_args_div.c parser/divide_coms.c parser/special_char_parser.c \
		parser/paste_envp.c parser/delete_protecting.c parser/create_final_mass.c \
		parser/check_args.c parser/create_com.c parser/find_com.c parser/make_redirect.c\
		\
		build_in/build_in.c build_in/exit_com.c build_in/export_build_in.c \
		build_in/export_out.c build_in/unset_com.c build_in/export_utils.c build_in/echo_com.c\
		\
		launch/delete_all.c launch/main.c launch/ft_start.c launch/run_com.c launch/launch_com.c \
		launch/fork_start.c launch/history_create.c launch/check_line.c launch/work_with_fd.c
OBJS = $(SRCS:c=o)
LIBFT = ./libft/libft.a
INCLUDES = includes

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	gcc -ltermcap $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJS): %.o : %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TERM_OBJS)
	$(MAKE) fclean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
