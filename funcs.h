/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:52:18 by fignigno          #+#    #+#             */
/*   Updated: 2021/03/27 17:16:58 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "main_struct.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <term.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>

void	exit_error(const char *str);
void	go_further(char *str, char c, int *i);
void	copy_envp(t_hist *hist, char **envp);
void	start(t_hist *hist);
t_com	**parse_com(char *str, t_envp *envp);
char	*copy_further(char *dst, char *src, char c);
void	add_str(t_arg **lst, char *str, int is_space);
int		is_special_char(char c);
// void	skip_spaces(char **str);
int		is_quote_or_space(char c);
char	*quote_found(char **str, char quote);
char	*spec_found(char **str, char *prev);
void	main_parcing(t_com *com, t_envp *envp);
int		end_spec(char cur, char prev);
char	*redirect_found(char **str);
char	*pipe_found();
void	paste_envp(t_arg *args, t_envp *envp);
void	delete_protecting(t_arg *arg);
char	**create_final_mass(t_arg *arg);
void	change_spaces(t_arg *arg);
void	init_save_term(struct termios *term);
char	*read_line(t_hist *hist);
int		check_files(t_com *com);
int		check_pipes(t_arg *list);
int		create_com(t_com *com);
void	run_com(t_com **com);
void	find_com(t_com *com, t_envp *env);
void	launch_com(t_com *com);
#endif
