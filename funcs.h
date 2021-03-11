/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/11 23:48:26 by fignigno         ###   ########.fr       */
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

#endif
