/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/13 23:36:06 by fignigno         ###   ########.fr       */
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
void	divide_coms(t_com **com, char *str);
char	*copy_further(char *dst, char *src, char c);
char	**add_str(char **mass, char *str);
void	skip_spaces(char **str);

#endif
