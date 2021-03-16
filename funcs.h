/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/16 23:20:37 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
#define FUNCS_H

#include "main_struct.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	exit_error(const char *str);
void	go_further(char *str, char c, int *i);
void	copy_envp(t_hist *hist, char **envp);
void	start(t_hist *hist);
void	parse_com(t_com **com, char *str, char **envp);
char	*copy_further(char *dst, char *src, char c);
void	add_str(t_arg **lst, char *str, int is_space);
int		is_special_char(char c);
// void	skip_spaces(char **str);
int		is_quote_or_space(char c);
char	*quote_found(char **str, char quote);
char	*spec_found(char **str);
void	main_parcing(t_com *com, char **envp);
int		end_spec(char cur, char prev);
char	*redirect_found(char **str);
char	*pipe_found(char **str);

#endif
